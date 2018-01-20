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

bool PCModule::render(IMonitorDisplay &display) const
{
	std::cout << "base display" << std::endl;
}

void PCModule::clear(IMonitorDisplay &display) const
{
	AMonitorModule::clear(display);
}

bool PCModule::getInfos()
{
	std::cout << "info" << std::endl;
	return true;
}

//bool PCModule::render(NcursesDisplay &display) const
//{
//	std::cout << "ok" << std::endl;
//}
