/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** AMonitorModule.cpp
*/

#include "AMonitorModule.hpp"

const std::string &AMonitorModule::getType() const
{
	return _type;
}

bool AMonitorModule::render(IMonitorDisplay &display) const
{
	(void)(display);
	return false;
}

void AMonitorModule::clear(IMonitorDisplay &display) const
{
	(void)(display);
}

bool AMonitorModule::getInfos()
{
	return false;
}
