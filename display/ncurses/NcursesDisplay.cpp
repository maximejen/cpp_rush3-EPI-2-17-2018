/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesDisplay.cpp
*/

#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay()
{
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
	refreshRender();
	getch();
	return false;
}

bool NcursesDisplay::refreshRender()
{
	refresh();
	return false;
}

bool NcursesDisplay::teardown()
{
	delwin(_mainwin);
	endwin();
	refresh();
	return false;
}
