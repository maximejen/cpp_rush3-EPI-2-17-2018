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
#include <sstream>

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

bool TimeModule::render(GTKDisplay &display) const
{
        auto frame = gtk_frame_new("TimeModule");
        gtk_widget_set_size_request(GTK_WIDGET(frame), getBox().getWidth(),
                                    getBox().getHeigth());
        gtk_fixed_put(GTK_FIXED(display._fixed), frame, getBox().getX(),
                      getBox().getY());
        auto fixed = gtk_fixed_new();
        gtk_container_add(GTK_CONTAINER(frame), fixed);
        auto label = gtk_label_new(getUpTime().c_str());
        int w;
        int h;
        gtk_widget_get_size_request(GTK_WIDGET(label), &w, &h);
        w = (getBox().getWidth() / 2) - (w / 2);
        h = (getBox().getHeigth() / 2) - (h / 2);
        gtk_fixed_put(GTK_FIXED(fixed), label, w, h);
}

bool TimeModule::render(NcursesDisplay &display) const
{
	return false;
}

void TimeModule::clear(NcursesDisplay &display) const
{
}

void TimeModule::clear(GTKDisplay &display) const
{
}
