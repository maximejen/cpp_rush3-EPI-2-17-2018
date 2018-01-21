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
int y, int w, int h): _type(type),
_box(static_cast<size_t>(x), static_cast<size_t>(y), static_cast<size_t>(w),
static_cast<size_t>(h))
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

bool AMonitorModule::setup()
{
	return false;
}

const Box &AMonitorModule::getBox() const
{
	return _box;
}

Box AMonitorModule::calcAbsSizeTerm(Box const &b) const
{
	struct winsize size = {};
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0) {
		std::cerr << "Cannot get term size" << std::endl;
		exit(1);
	}
	size.ws_row = static_cast<unsigned short>(size.ws_row - 1);
	auto posX = static_cast<int>(size.ws_col *
		(static_cast<float>(b.getX()) / 100));
	auto posY = static_cast<int>(size.ws_row *
		(static_cast<float>(b.getY()) / 100));
	auto width = static_cast<int>(size.ws_col *
		(static_cast<float>(b.getWidth()) / 100));
	auto height = static_cast<int>(size.ws_row *
	(static_cast<float>(b.getHeigth()) / 100));
	return Box(posX, posY, width, height);
}

void AMonitorModule::event(int)
{
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

bool Vec::operator==(const Vec &vec)
{
	return this->getX() == vec.getX() && this->getY() == vec.getY();
}

bool Vec::operator>(const Vec &vec)
{
	auto ret = true;

	if (this->getX() < vec.getX() || this->getY() < vec.getY())
		ret = false;
	return ret;
}

bool Vec::operator<(const Vec &vec)
{
	auto ret = true;

	if (this->getX() > vec.getX() || this->getY() > vec.getY())
		ret = false;
	return ret;
}
