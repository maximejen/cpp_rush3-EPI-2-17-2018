/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** PCModule.cpp
*/
#include <fstream>
#include <iostream>
#include "PCModule.hpp"

PCModule::PCModule(int x, int y, int w, int h)
: AMonitorModule("PCModule", x, y, w, h)
{
}

PCModule::PCModule(const Box &box)
: AMonitorModule("PCModule", box)
{
}

bool PCModule::render(GTKDisplay &display) const
{
	(void)display;
	std::cout << "GTK" << std::endl;
	return false;
}

bool PCModule::render(NcursesDisplay &display) const
{
	(void)display;
	std::cout << "Ncurses" << std::endl;
	return false;
}

void PCModule::clear(NcursesDisplay &display) const
{
	AMonitorModule::clear(display);
}

void PCModule::clear(GTKDisplay &display) const
{
	AMonitorModule::clear(display);
}

bool PCModule::getInfos()
{
	std::cout << "info" << std::endl;
	return true;
}
