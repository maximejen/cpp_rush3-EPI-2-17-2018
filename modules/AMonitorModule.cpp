/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** AMonitorModule.cpp
*/

#include <iostream>
#include "AMonitorModule.hpp"

AMonitorModule::AMonitorModule(const std::string &type, int x,
int y, int w, int h): _type(type), _box(x, y, w, h)
{

}

AMonitorModule::AMonitorModule(const std::string &type, const Box &box)
: _type(type), _box(box)
{

}

const std::string &AMonitorModule::getType() const
{
	return _type;
}

bool AMonitorModule::render(GTKDisplay &display) const
{
	return false;
}

bool AMonitorModule::render(NcursesDisplay &display) const
{
	return false;
}

void AMonitorModule::clear(NcursesDisplay &display) const
{
	(void)(display);
}

void AMonitorModule::clear(GTKDisplay &display) const
{
	(void)(display);
}

bool AMonitorModule::getInfos()
{
	return false;
}

const Box &AMonitorModule::getBox() const
{
	return _box;
}

Box::Box(int x, int y, int width, int heigth)
: x(x), y(y), width(width), heigth(heigth)
{
}

int Box::getX() const
{
	return x;
}

int Box::getY() const
{
	return y;
}

int Box::getWidth() const
{
	return width;
}

int Box::getHeigth() const
{
	return heigth;
}
