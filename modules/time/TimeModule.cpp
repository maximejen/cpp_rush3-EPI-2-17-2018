/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** TimeModule.cpp
*/

#include <sstream>
#include <ctime>
#include <iostream>
#include <fstream>
#include <ncurses/tool/NcursesTool.hpp>
#include "TimeModule.hpp"

TimeModule::TimeModule(int x, int y, int w, int h)
: AMonitorModule("TimeModule", x, y, w, h)
{
}

std::string TimeModule::getUpTime() const
{
	std::stringstream date;
	std::ifstream file(uptimeFile);
	int uptime;
	file >> uptime;

	int days = uptime / (60 * 60 * 24);
	int hours = uptime / (60 * 60);
	int minutes = (uptime / 60) % 60;
	int seconds = uptime % 60;
	date << days << "d " << hours << "h " << minutes << "m " << seconds
	     << "s.";
	return date.str();
}

std::string TimeModule::getDate() const
{
	auto time = std::time(nullptr);

	return std::ctime(&time);
}

bool TimeModule::render(NcursesDisplay &display) const
{
	NcursesTool::drawBox(display, getBox());
	Vec v(10, 10);
	NcursesTool::drawText(display, getBox(), v, "Date: " + date);
	v.setXY(10, 50);
	NcursesTool::drawText(display, getBox(), v, "Uptime: " + uptime);
	return false;
}

bool TimeModule::render(GTKDisplay &display) const
{
	return false;
}

bool TimeModule::getInfos()
{
	uptime = getUpTime();
	date = getDate();
	return true;
}
