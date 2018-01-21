/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "PCModule.hpp"
#include "ncurses/tool/NcursesTool.hpp"
#include <fstream>
#include <iostream>


PCModule::PCModule(int x, int y, int w, int h) :
AMonitorModule("PCModule", x, y, w, h),
osReleaseFile("/etc/os-release"),
kernelOSReleaseFile("/proc/sys/kernel/osrelease"),
kernelOSTypeFile("/proc/sys/kernel/ostype"),
pcModelFile("/sys/devices/virtual/dmi/id/product_name"),
show(true)
{
	this->reloadModule();
	_frame = gtk_frame_new("User Module");
	gtk_widget_set_size_request(GTK_WIDGET(_frame), (w - 2) * 1280 / 100,
	                            (h - 2) * 720 / 100);
	_fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(_frame), _fixed);
	_label = gtk_label_new("");
	gtk_fixed_put(GTK_FIXED(_fixed), _label, 10, 10);
	gtk_label_set_use_markup(GTK_LABEL(_label), TRUE);
}

PCModule::~PCModule()
{
}

bool PCModule::setup()
{
	return true;
}

std::string PCModule::prepareVersion(std::string &str) const
{
	str += "<span size=\"large\">OS Name</span>: <span "
	        "size=\"x-large\"><b>";
	str += osInfos.at("NAME").c_str();
	str += "</b></span>\n";
	str += "<span size=\"large\">OS Version</span>: <span "
	        "size=\"x-large\"><b>";
	str += osInfos.at("VERSION").c_str();
	str += "</b></span>";
	return str;
}

bool PCModule::render(NcursesDisplay &d) const
{
	if (!show)
		return false;
	Box b = calcAbsSizeTerm(getBox());
	NcursesTool::drawBox(d, b, "Ordinateur");
	Vec v(20, 10);
	NcursesTool::drawText(d, b, v, "Nom : " + pcModel + " ");
	v.setY(40);
	NcursesTool::drawText(d, b, v, "Kernel : " + kernelVersion + " ");
	v.setY(60);
	try {
		NcursesTool::drawText(d, b, v,
		                      "OS : " + osInfos.at("NAME") + " ");
		v.setY(80);
		NcursesTool::drawText(
		    d, b, v,
		    "Version de l'OS : " + osInfos.at("VERSION") + " ");
	}
	catch (std::exception const &) {
	}
	return true;
}

bool PCModule::render(GTKDisplay &display) const
{
	if (!display.isIn(this)) {
		display.addToDisplay(this, _frame, getBox().getX() + 1,
		                     getBox().getY() + 1);
	}
	std::string _str =
	    "<span size=\"large\">Nom</span>: <span size=\"x-large\"><b>";
	_str += pcModel.c_str();
	_str += "</b></span>\n<span size=\"large\">Kernel</span>: <span "
	        "size=\"x-large\"><b>";
	_str += kernelVersion.c_str();
	_str += "</b></span>\n";
	try {
		_str = prepareVersion(_str);
	}
	catch (...) {
		_str += "</b></span>";
	}
	gtk_label_set_use_markup(GTK_LABEL(_label), TRUE);
	gtk_label_set_markup(GTK_LABEL(_label), _str.c_str());
	return true;
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
			for (i = 0; i < tmp.size() && tmp[i] != '='; i++)
				;
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
