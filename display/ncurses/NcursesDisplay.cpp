/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesDisplay.cpp
*/
#include <iostream>
#include "PC/PCModule.hpp"
#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay(): _mainwin(), _modules()
{
	_modules.push_back(new PCModule(0, 0, 0, 0));
}

bool NcursesDisplay::setup()
{
	_mainwin = initscr();
	noecho();
	curs_set(0);
	return false;
}

bool NcursesDisplay::render()
{
	clearRender();
	for (auto &n : _modules) {
		if (!n->getInfos())
			continue;
		n->render(*this);
	}
	refreshRender();
	return true;
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

bool NcursesDisplay::clearRender()
{
	clear();
	return true;
}

NcursesDisplay::~NcursesDisplay()
{
	for (auto &n : _modules) {
		delete n;
	}
}
