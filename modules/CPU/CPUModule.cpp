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
#include "ncurses/tool/NcursesTool.hpp"
#include "CPUModule.hpp"

CPUModule::CPUModule(int x, int y, int w, int h)
: AMonitorModule("CPUModule", x, y, w, h),
cpu(std::thread::hardware_concurrency()), histo_idx(),
histo(cpu), previous_idle(cpu), previous_total(cpu)
{
}

CPUModule::CPUModule(const Box &box): AMonitorModule("CPUModule", box),
cpu(std::thread::hardware_concurrency()), histo_idx(),
histo(cpu), previous_idle(cpu), previous_total(cpu)
{
}

bool CPUModule::render(NcursesDisplay &display) const
{
	std::vector<int> nex(this->histo[0].begin(), this->histo[0]
		.end());
	Histo h(0, 0, 100, 100, nex, "CPU");
	NcursesTool::drawHisto(display, this->getBox(), h);
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

bool CPUModule::get_next_cpu(std::ifstream &stat, int idx)
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

bool CPUModule::getInfos()
{
	std::ifstream proc_stat("/proc/stat");
	if (!proc_stat.is_open())
		return false;
	for (unsigned int i = 0; i < this->cpu ; i++) {
		if (!get_next_cpu(proc_stat, i))
			return false;
	}
	return true;
}

