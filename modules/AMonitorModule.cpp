/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** AMonitorModule.cpp
*/

#include "AMonitorModule.hpp"

AMonitorModule::AMonitorModule(const std::string &_type)
: _type(_type)
{
}

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

box::box(int x, int y, int width, int heigth)
: x(x), y(y), width(width), heigth(heigth)
{
}

int box::getX() const
{
	return x;
}

int box::getY() const
{
	return y;
}

int box::getWidth() const
{
	return width;
}

int box::getHeigth() const
{
	return heigth;
}
