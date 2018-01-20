/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include "gtk/GTKDisplay.hpp"
#include "PCModule.hpp"

PCModule::PCModule(const std::string &type) : AMonitorModule(type)
{
}

PCModule::~PCModule()
{
}

const std::string &PCModule::getType() const
{
}

bool PCModule::render(IMonitorDisplay &display) const
{
	std::cout << "Display" << std::endl;
}

bool PCModule::render(GTKDisplay &display) const
{
	std::cout << "GTK" << std::endl;
}

void PCModule::clear(IMonitorDisplay &display) const
{
}

bool PCModule::getInfos()
{
}
