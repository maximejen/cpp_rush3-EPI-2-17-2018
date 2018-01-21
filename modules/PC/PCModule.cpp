/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <fstream>
#include "ncurses/tool/NcursesTool.hpp"
#include "PCModule.hpp"


PCModule::PCModule(int x, int y, int w, int h) :
AMonitorModule("PCModule", x, y, w, h),
osReleaseFile("/etc/os-release"),
kernelOSReleaseFile("/proc/sys/kernel/osrelease"),
kernelOSTypeFile("/proc/sys/kernel/ostype"),
pcModelFile("/sys/devices/virtual/dmi/id/product_name"),
show(true)
{
	this->reloadModule();
}

PCModule::~PCModule()
{
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

bool PCModule::render(NcursesDisplay &d) const
{
	if (!show)
		return false;
	Box b = calcAbsSizeTerm(getBox());
	NcursesTool::drawBox(d, b, "Ordinateur");
	Vec v(20,10);
	NcursesTool::drawText(d, b, v, "Nom : " + pcModel + " ");
	v.setY(40);
	NcursesTool::drawText(d, b, v, "Kernel : " + kernelVersion + " ");
	v.setY(60);
	try {
		NcursesTool::drawText(d, b, v, "OS : " +
		osInfos.at("NAME") + " ");
		v.setY(80);
		NcursesTool::drawText(d, b, v, "Version de l'OS : " +
	osInfos.at("VERSION") + " ");
	} catch (std::exception const &) { }
	return true;
}

bool PCModule::render(GTKDisplay &display) const
{
	(void)display;
	return false;
}

bool PCModule::setup()
{
	return true;
}

void PCModule::reloadModule()
{
	std::string tmp;
	std::ifstream filePCModel(this->pcModelFile);
	std::ifstream file1(this->kernelOSReleaseFile);
	std::ifstream file2(this->kernelOSTypeFile);
	std::ifstream file3(this->osReleaseFile);

	kernelVersion += sizeof(int *) == 8 ? "x86_64 " : "x84 ";
	if (filePCModel.is_open())
		std::getline(filePCModel, this->pcModel);
	if (file2.is_open() && file2 >> tmp)
		this->kernelVersion += tmp + ' ';
	if (file1.is_open() && file1 >> tmp)
		this->kernelVersion += tmp;
	if (file3.is_open())
		while (!file3.eof() && std::getline(file3, tmp)) {
			unsigned long i = 0;
			for (i = 0 ; i < tmp.size() && tmp[i] != '=' ; i++);
			this->osInfos[tmp.substr(0, i)] =
			tmp.substr(i + 1, tmp.size() - (i + 1));
		}
}

void PCModule::event(int c)
{
	if (c == 'o')
		show = !show;
}

bool PCModule::isShow() const
{
	return show;
}
