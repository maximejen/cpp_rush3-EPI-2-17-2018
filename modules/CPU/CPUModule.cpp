/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** CPUModule.cpp
*/

#include <thread>
#include <numeric>
#include <iostream>
#include <sstream>
#include <regex>
#include "ncurses/tool/NcursesTool.hpp"
#include "CPUModule.hpp"

CPUModule::CPUModule(int x, int y, int w, int h)
: AMonitorModule("CPUModule", x, y, w, h),
cpu(std::thread::hardware_concurrency()), histo_idx(),
histo(cpu + 1), previous_idle(cpu + 1), previous_total(cpu + 1)
{
}

CPUModule::CPUModule(const Box &box): AMonitorModule("CPUModule", box),
cpu(std::thread::hardware_concurrency()), histo_idx(),
histo(cpu + 1), previous_idle(cpu + 1), previous_total(cpu + 1)
{
}

bool CPUModule::render(NcursesDisplay &display) const
{
	size_t i;
	auto nbGraphs = this->cpu + 1;
	auto absBox = this->calcAbsSizeTerm(this->getBox());
	std::vector<std::vector<int>> histo_int;
	for (auto &n : this->histo) {
		auto newV = std::vector<int>();
		for (auto &a : n)
			newV.push_back(static_cast<int>(a));
		histo_int.push_back(newV);
	}
	std::string tag = "cpu";
	for (i = 0; i < this->histo.size(); i++) {
		Histo h(i * 100 / nbGraphs, 0, 100 / nbGraphs,
		        100, histo_int[i], tag);
		NcursesTool::drawHisto(display, absBox, h);
		tag = "cpu" + std::to_string(i);
	}
	return true;
}

bool CPUModule::render(GTKDisplay &display) const
{
	(void)display;
	return false;
}

void CPUModule::clear(NcursesDisplay &display) const
{
	(void)(display);
}

void CPUModule::clear(GTKDisplay &display) const
{
	(void)(display);
}

bool CPUModule::get_next_cpu(std::ifstream &stat, size_t idx)
{
	std::string line;
	std::getline(stat, line);
	std::istringstream ss(line);
	std::vector<size_t> times;
	size_t t;
	ss >> line;
	while (ss >> t)
		times.push_back(t);
	if (times.size() < 4)
		return false;
	auto total = std::accumulate(times.begin(), times.end(), 0);
	const float idle_time_delta = times[3] - this->previous_idle[idx];
	const float total_time_delta = total - this->previous_total[idx];
	auto utilization = 100.0 * (1.0 - idle_time_delta / total_time_delta);
	this->previous_idle[idx] = times[3];
	this->previous_total[idx] = total;
	this->histo[idx].push_back(utilization);
	return true;
}

bool CPUModule::setup()
{
	std::ifstream proc_stat("/proc/stat");
	if (!proc_stat.is_open())
		return false;
	for (size_t i = 0; i < this->cpu + 1; i++) {
		if (!get_next_cpu(proc_stat, i))
			return false;
	}
	return true;
}

void CPUModule::getFrequence()
{
	std::smatch res;
	std::regex regex("^cpu MHz\\s+:\\s+(.+)$");
	std::ifstream proc_stat("/proc/cpuinfo");
	if (!proc_stat.is_open())
		return;
	std::string line;
	while (std::getline(proc_stat, line)) {
		if (std::regex_search(line, res, regex)) {
			this->model = std::string(res[1]) + " MHz";
		}
	}
}

void CPUModule::getModel()
{
	std::smatch res;
	std::regex regex("^model name\\s+:\\s+(.+)$");
	std::ifstream proc_stat("/proc/cpuinfo");
	if (!proc_stat.is_open())
		return;
	std::string line;
	while (std::getline(proc_stat, line)) {
		if (std::regex_search(line, res, regex)) {
			this->model = res[1];
		}
	}
}

