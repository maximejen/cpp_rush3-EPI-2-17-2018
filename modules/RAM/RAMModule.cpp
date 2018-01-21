/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** RAMModule.cpp
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include "RAMModule.hpp"

const std::string memInfosFile = "/proc/meminfo";

RAMModule::RAMModule(int x, int y, int w, int h) :
AMonitorModule("RAMModule", x, y, w, h)
{
	this->reloadData();
}

RAMModule::~RAMModule()
{
}

bool RAMModule::render(NcursesDisplay &display) const
{
	(void)display;
	return false;
}

bool RAMModule::render(GTKDisplay &display) const
{
	(void)display;
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
			for (i = 0 ; i < t.size() && t[i] != ':' ; i++);
			for (j = i + 1 ; i < t.size() && t[j] == ' ' ; j++);
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
