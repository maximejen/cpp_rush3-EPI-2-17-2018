/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <fstream>
#include "PCModule.hpp"

PCModule::PCModule(int x, int y, int w, int h) :
AMonitorModule("PCModule", x, y, w, h)
{
	std::string tmp1;

	if (sizeof(int *) == 8)
		this->kernelVersion += "x86_64 ";
	else
		this->kernelVersion += "x86 ";

	std::ifstream filePCModel(this->pcModelFile);
	if (filePCModel.is_open())
		std::getline(filePCModel, this->pcModel);

	std::ifstream file2(this->kernelOSTypeFile);
	if (file2.is_open()) {
		file2 >> tmp1;
		this->kernelVersion += tmp1 + ' ';
	}

	std::ifstream file1(this->kernelOSReleaseFile);
	if (file1.is_open()) {
		file1 >> tmp1;
		this->kernelVersion += tmp1;
	}

	std::ifstream file3(this->osReleaseFile);
	if (file3.is_open()) {
		std::string tmp;
		while (!file3.eof() && std::getline(file3, tmp)) {
			unsigned long i = 0;
			for (i = 0 ; i < tmp.size() && tmp[i] != '=' ; i++);
			this->osInfos[tmp.substr(0, i)] =
			tmp.substr(i + 1, tmp.size() - (i + 1));
		}
	}
}

PCModule::~PCModule()
{
}

bool PCModule::render(IMonitorDisplay &display) const
{
	(void)display;
	std::cout << "Display" << std::endl;
	return false;
}

const std::map<std::string, std::string> &PCModule::getOsInfos() const
{
	return this->osInfos;
}

const std::string &PCModule::getKernelVersion() const
{
	return this->kernelVersion;
}

const std::string &PCModule::getPCModel() const
{
	return this->pcModel;
}

bool PCModule::render(NcursesDisplay &display) const
{
	(void)display;
	return false;
}

bool PCModule::render(GTKDisplay &display) const
{
	(void)display;
	return false;
}
