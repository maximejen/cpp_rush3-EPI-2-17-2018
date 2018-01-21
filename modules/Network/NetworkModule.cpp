/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NetworkModule.cpp
*/

#include <fstream>
#include <iostream>
#include <ncurses/tool/NcursesTool.hpp>
#include <numeric>
#include "NetworkModule.hpp"

NetworkModule::NetworkModule(int x, int y, int w, int h)
: AMonitorModule("NetworkModule", x, y, w, h), networkFile("/proc/net/dev"),
connexions()
{
}

void NetworkModule::normalize_max(
std::vector<unsigned long long> histo,
unsigned long long int &max)
{
	if (histo.size() < 3)
		return;
	auto size = histo.size();
	auto last_diff = histo[size - 1] - histo[size - 2];
	auto old_last_diff = histo[size - 2] - histo[size - 3];
	if (histo[size - 1] >= max / 2 ||
		last_diff < old_last_diff)
		max += max / 10;
	else if (histo[size - 1] <= max / 2 ||
		(last_diff > old_last_diff && max > 10))
		max -= max / 10;
}

std::vector<int> NetworkModule::normalize_network(
std::vector<unsigned long long> origin,
unsigned long long int max) const
{
	std::vector<int> converted;
	for (auto &n : origin)
		converted.push_back(static_cast<int &&>(n * 100 / max));
	return converted;
}

bool NetworkModule::render(NcursesDisplay &display) const
{
	auto nbGraphs = this->connexions.size();
	auto absBox = this->calcAbsSizeTerm(this->getBox());
	int i = 0;
	for (auto &n : this->connexions) {
		auto array = this->normalize_network(n.second[0],
		this->max.at(n.first)[0]);
		Histo h1(i * 100 / nbGraphs, 0, 100 / nbGraphs,
		        50, array, n.first);
		NcursesTool::drawHisto(display, absBox, h1);
		array = this->normalize_network(n.second[1],
		this->max.at(n.first)[1]);
		Histo h2(i * 100 / nbGraphs, 50, 100 / nbGraphs,
		        50, array, n.first);
		NcursesTool::drawHisto(display, absBox, h2);
		i += 1;
	}
	return true;
}

bool NetworkModule::render(GTKDisplay &display) const
{
	(void)display;
	return false;
}

bool NetworkModule::setup_connexions(const std::string &inter,
const std::string &value)
{
	std::istringstream ss(value);
	std::vector<unsigned long long int> values;
	unsigned long long int t;
	while (ss >> t)
		values.push_back(t);
	if (values.size() < 9)
		return false;
	auto t1 =  this->connexions[inter][0].end();
	auto t2 =  this->connexions[inter][1].end();
	if (this->max.find(inter) == this->max.end() || values[0] - *(t1 - 1))
		this->connexions[inter][0].push_back(values[0]);
	if (this->max.find(inter) == this->max.end() || values[8] - *(t2 - 1))
		this->connexions[inter][1].push_back(values[8]);
	if (this->max.find(inter) == this->max.end()) {
		this->max[inter][0] = values[0] + 11;
		this->max[inter][1] = values[8] + 11;
	} else {
		this->normalize_max(connexions[inter][0], max[inter][0]);
		this->normalize_max(connexions[inter][1], max[inter][1]);
	}
	return true;
}

bool NetworkModule::setup()
{
	std::smatch res;
	std::regex regex("^(.+):\\s+(.+)+$");
	std::ifstream netFile(this->networkFile);
	if (!netFile.is_open())
		return false;
	std::string line;
	for (int i = 0; std::getline(netFile, line); i++)
		if (i < 2)
			continue;
		else if (std::regex_search(line, res, regex)) {
			setup_connexions(res[1], res[2]);
		}
	return true;
}

NetworkModule::~NetworkModule()
{
}
