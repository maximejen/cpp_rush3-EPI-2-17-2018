/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** AMonitorModule.cpp
*/

#include <iostream>
#include "IMonitorDisplay.hpp"
#include "AMonitorModule.hpp"

AMonitorModule::AMonitorModule(const std::string &type, int x,
int y, int w, int h): _type(type), _box(x, y, w, h)
{

}

AMonitorModule::AMonitorModule(const std::string &type, const Box &box)
: _type(type), _box(box)
{

}

AMonitorModule::~AMonitorModule()
{
}

const std::string &AMonitorModule::getType() const
{
	return _type;
}

bool AMonitorModule::render(GTKDisplay &display) const
{
	(void)display;
	return false;
}

bool AMonitorModule::render(NcursesDisplay &display) const
{
	(void)display;
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

Box::Box(size_t x, size_t y, size_t width, size_t heigth)
: x(x), y(y), width(width), heigth(heigth)
{
}

size_t Box::getX() const
{
	return x;
}

size_t Box::getY() const
{
	return y;
}

size_t Box::getWidth() const
{
	return width;
}

size_t Box::getHeigth() const
{
	return heigth;
}

size_t Box::getAbsoluteW() const
{
	return x + width;
}

size_t Box::getAbsoluteH() const
{
	return y + heigth;
}

size_t Vec::getX() const
{
	return x;
}

size_t Vec::getY() const
{
	return y;
}

Vec::Vec(size_t x, size_t y) : x(x), y(y)
{
}

void Vec::setX(size_t x)
{
	this->x = x;
}

void Vec::setY(size_t y)
{
	this->y = y;
}

void Vec::setXY(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
}
