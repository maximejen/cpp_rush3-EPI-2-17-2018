/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** TimeModule.cpp
*/

#include "TimeModule.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <ncurses/tool/NcursesTool.hpp>
#include <sstream>
#include "TimeModule.hpp"

TimeModule::TimeModule(int x, int y, int w, int h)
    : AMonitorModule("TimeModule", x, y, w, h)
{
	_frame = gtk_frame_new("Time Module");
	gtk_widget_set_size_request(GTK_WIDGET(_frame), getBox().getWidth(),
	                            getBox().getHeigth());
	_isFixed = false;
	_fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(_frame), _fixed);
	_str = "Uptime: <span size=\"x-large\"><b>";
	_str += getUpTime().c_str();
	_str += "</b></span>\nSince: <span size=\"x-large\"><b>";
	_str += getDate().c_str();
	_str += "</b></span>";
	_label = gtk_label_new(_str.c_str());
	gtk_label_set_use_markup(GTK_LABEL(_label), TRUE);
	gtk_label_set_markup(GTK_LABEL(_label), _str.c_str());
	gtk_fixed_put(GTK_FIXED(_fixed), _label, 20, 5);
}

std::string TimeModule::getUpTime() const
{
	std::ostringstream date;
	std::ifstream file(uptimeFile);
	if (file.is_open()) {
		int uptime;
		file >> uptime;

		int days = uptime / (60 * 60 * 24);
		int hours = uptime / (60 * 60) % 24;
		int minutes = (uptime / 60) % 60;
		int seconds = uptime % 60;
		date << days << "d " << hours << "h " << minutes << "m "
		     << seconds << "s.";
		return date.str();
	}
	return "";
}

std::string TimeModule::getDate() const
{
	auto time = std::time(nullptr);

	return std::ctime(&time);
}

bool TimeModule::setup()
{
	_str = "Uptime: <span size=\"x-large\"><b>";
	_str += getUpTime().c_str();
	_str += "</b></span>\nSince: <span size=\"x-large\"><b>";
	_str += getDate().c_str();
	_str += "</b></span>";
	return true;
}

bool TimeModule::render(GTKDisplay &display) const
{
	if (display.isIn(this) == false) {
		std::cout << "Added !" << std::endl;
		display.addToDisplay(this, _frame, getBox().getX(),
		                     getBox().getY());
	}
	gtk_label_set_markup(GTK_LABEL(_label), _str.c_str());
	return true;
}

bool TimeModule::render(NcursesDisplay &display) const
{
	Vec v(10, 10);
	NcursesTool::drawBox(display, getBox());
	NcursesTool::drawText(display, getBox(), v, "Date: " + _date);
	v.setXY(10, 50);
	NcursesTool::drawText(display, getBox(), v, "Uptime: " + _uptime);
	return false;
}

void TimeModule::clear(NcursesDisplay &display) const
{
	(void)display;
}

void TimeModule::clear(GTKDisplay &display) const
{
	(void)display;
}

bool TimeModule::getInfos()
{
	uptime = getUpTime();
	date = getDate();
	return true;
}
