/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** AMonitorModule.cpp
*/

#include <iostream>
#include <sys/ioctl.h>
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

Box AMonitorModule::calcAbsSizeTerm(Box const &b) const
{
	struct winsize size;
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0) {
		std::cerr << "Cannot get term size" << std::endl;
		exit(1);
	}
	auto posX = static_cast<int>(size.ws_col *
		(static_cast<float>(b.getX()) / 100));
	auto posY = static_cast<int>(size.ws_row *
		(static_cast<float>(b.getY()) / 100));
	auto width = static_cast<int>(size.ws_col *
		(static_cast<float>(b.getWidth()) / 100));
	auto height = static_cast<int>(size.ws_row *
	(static_cast<float>(b.getHeigth()) / 100));;
	return Box(posX, posY, width, height);
}

void AMonitorModule::event(char)
{
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

int Box::getAbsoluteW() const
{
	return x + width;
}

int Box::getAbsoluteH() const
{
	return y + heigth;
}

int Vec::getX() const
{
	return x;
}

int Vec::getY() const
{
	return y;
}

Vec::Vec(int x, int y) : x(x), y(y)
{
}

void Vec::setX(int x)
{
	this->x = x;
}

void Vec::setY(int y)
{
	this->y = y;
}

void Vec::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}
