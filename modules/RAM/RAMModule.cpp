/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** RAMModule.cpp
*/
#include "RAMModule.hpp"
#include <fstream>
#include <iostream>
#include <ncurses/tool/NcursesTool.hpp>
#include <sstream>

const std::string memInfosFile = "/proc/meminfo";

RAMModule::RAMModule(int x, int y, int w, int h)
    : AMonitorModule("RAMModule", x, y, w, h), show(true)
{
	this->reloadData();
	_frame = gtk_frame_new("RAM Module");
	gtk_widget_set_size_request(GTK_WIDGET(_frame), (w - 2) * 1280 / 100,
	                            (h - 2) * 720 / 100);
	_fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(_frame), _fixed);
	_bar = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(_bar), 1.0);
	gtk_progress_bar_set_text(GTK_PROGRESS_BAR(_bar), "RAM Usage");
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(_bar), TRUE);
	int width = 0;
	int height = 0;
	gtk_widget_get_size_request(GTK_WIDGET(_bar), &width, &height);
	gtk_widget_set_size_request(GTK_WIDGET(_bar), 0.6 * w * 1280 / 100,
	                            height);
	gtk_fixed_put(GTK_FIXED(_fixed), _bar, 0.2 * w * 1280 / 100, h / 2);
}

RAMModule::~RAMModule()
{
}

bool RAMModule::render(NcursesDisplay &display) const
{
	if (show) {
		Box b = calcAbsSizeTerm(getBox());
		NcursesTool::drawBox(display, b, "Consomation RAM");
		Percent p(10, ((swap == 0) ? 50 : 33), 80, getMemoryP());
		NcursesTool::drawPercent(display, b, p);
		Vec v(45, (swap == 0) ? 75 : 50);
		std::stringstream s;
		s << "Etat des RAM : " << getMemoryP() << "% ";
		NcursesTool::drawText(display, b, v, s.str());
		if (swap != 0) {
			p.pos.setY(66);
			p.value = getSwapP();
			NcursesTool::drawPercent(display, b, p);
			v.setY(75);
			std::stringstream s;
			s << "Etat du SWAP: " << getSwapP() << "% ";
			NcursesTool::drawText(display, b, v, s.str());
		}
	}
	return show;
}

bool RAMModule::render(GTKDisplay &display) const
{
	if (!display.isIn(this)) {
		display.addToDisplay(this, _frame, getBox().getX() + 1,
		                     getBox().getY() + 1);
	}
	std::stringstream s;
	s << "Etat des RAM : " << getMemoryP() << "% ";
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(_bar),
	                              static_cast<float>(getMemoryP()) / 100.0);
	gtk_progress_bar_set_text(GTK_PROGRESS_BAR(_bar), s.str().c_str());
	return false;
}

const std::map<std::string, std::string> &RAMModule::getMemInfos() const
{
	return memInfos;
}

void RAMModule::reloadData()
{
	std::ifstream file(memInfosFile);
	std::string t;

	if (file.is_open()) {
		while (!file.eof() && std::getline(file, t)) {
			size_t i = 0;
			size_t j = 0;
			for (i = 0; i < t.size() && t[i] != ':'; i++)
				;
			for (j = i + 1; i < t.size() && t[j] == ' '; j++)
				;
			this->memInfos[t.substr(0, i)] =
			    t.substr(j, t.size() - j - 3);
		}
		this->max = std::stoul(this->memInfos["MemTotal"]);
		this->free = std::stoul(this->memInfos["MemFree"]);
		this->available = std::stoul(this->memInfos["MemAvailable"]);
		this->swap = std::stoul(this->memInfos["SwapTotal"]);
		this->swapfree = std::stoul(this->memInfos["SwapFree"]);
	}
}

bool RAMModule::setup()
{
	this->reloadData();
	return true;
}

size_t RAMModule::getUsedMemory() const
{
	size_t used;

	used = this->max - this->available;
	std::cerr << used * 100 / this->max << std::endl;
	return used;
}

size_t RAMModule::getMemoryP() const
{
	size_t used;

	used = this->max - this->available;
	return used * 100 / this->max;
}

size_t RAMModule::getSwapP() const
{
	size_t used;

	used = this->swap - this->swapfree;
	return used * 100 / this->swap;
}

void RAMModule::event(int c)
{
	if (c == 'r')
		show = !show;
}

bool RAMModule::isShow() const
{
	return show;
}
