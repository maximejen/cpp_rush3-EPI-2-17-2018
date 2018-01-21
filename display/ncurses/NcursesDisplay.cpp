/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesDisplay.cpp
*/
#include <iostream>
#include <time/TimeModule.hpp>
#include <sys/ioctl.h>
#include <RAM/RAMModule.hpp>
#include "CPU/CPUModule.hpp"
#include "PC/PCModule.hpp"
#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay(): _mainwin()
{
}

bool NcursesDisplay::setup()
{
	_mainwin = initscr();
	noecho();
	curs_set(0);
	timeout(100);
	keypad(stdscr, true);
	return false;
}

bool NcursesDisplay::render(ModulePager &mp)
{
	while (true) {
		auto c = getch();
		if (!event(mp, c))
			return false;
		clearRender();
		for (auto &n : mp.getCurPage().module) {
			struct winsize size;
			if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
				return false;
			if (!n->setup())
				continue;
			n->render(*this);
			n->event(c);
		}
		printPageInfo(mp);
		refreshRender();
	}
}

bool NcursesDisplay::refreshRender()
{
	refresh();
	return true;
}

bool NcursesDisplay::teardown()
{
	delwin(_mainwin);
	endwin();
	refresh();
	return true;
}

WINDOW *NcursesDisplay::getWindow() const
{
	return _mainwin;
}

bool NcursesDisplay::clearRender()
{
	clear();
	return true;
}

NcursesDisplay::~NcursesDisplay()
{
}

bool NcursesDisplay::event(ModulePager &mp, int c)
{
	(void) mp;
	if (c == 'q')
		return false;
	if (c == KEY_RIGHT)
		mp.inc();
	if (c == KEY_LEFT)
		mp.dec();
	return true;
}

void NcursesDisplay::printPageInfo(ModulePager const &mp)
{
	struct winsize size = {};
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0) {
		std::cerr << "Cannot get term size" << std::endl;
		exit(1);
	}
	Page p = mp.getCurPage();
	auto x = (size.ws_col / 2) - ((p.name.size() + 2) / 2);
	mvprintw(size.ws_row - 1, x, "[%s]", mp.getCurPage().name.c_str());
	mvprintw(size.ws_row - 1, 0, "%c", '<');
	mvprintw(size.ws_row - 1, size.ws_col - 1, "%c", '>');
}
