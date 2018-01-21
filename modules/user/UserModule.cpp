/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** UserModule.cpp
*/

#include "UserModule.hpp"
#include <grp.h>
#include <iostream>
#include <ncurses/tool/NcursesTool.hpp>
#include <pwd.h>
#include <sstream>
#include <zconf.h>

UserModule::UserModule(int x, int y, int w, int h) :
AMonitorModule("UserModule", x, y, w, h), _username(getlogin()),
_uid(getuid()), show(true)
{
	int ngroups = 100;
	gid_t groups[10];
	char hostName[1024];

	getgrouplist(this->_username.c_str(), 0, groups, &ngroups);
	for (int i = 0; i < ngroups; i++) {
		this->_groupGID.push_back(groups[i]);
		auto g = getgrgid(groups[i]);
		this->_groupNames.push_back(std::string(g->gr_name));
	}
	this->_sid = getsid(getpid());
	auto pw = getpwuid(static_cast<__uid_t>(this->_uid));
	this->_homePath = std::string(pw->pw_dir);
	this->_defaultShell = std::string(pw->pw_shell);
	gethostname(hostName, 1023);
	this->_hostName = std::string(hostName);
	this->_loaded = false;
}

UserModule::~UserModule()
{
}

const std::string &UserModule::getUsername() const
{
	return _username;
}

int UserModule::getUid() const
{
	return _uid;
}

const std::vector<gid_t> &UserModule::getGroupGID() const
{
	return _groupGID;
}

const std::vector<std::string> &UserModule::getGroupNames() const
{
	return _groupNames;
}

const std::string &UserModule::getHomePath() const
{
	return _homePath;
}

const std::string &UserModule::getDefaultShell() const
{
	return _defaultShell;
}

int UserModule::getSid() const
{
	return _sid;
}

const std::string &UserModule::getHostName() const
{
	return _hostName;
}

void UserModule::render_Ncurse(NcursesDisplay &display, Box const &b,
Vec &v) const
{
	v.setY(45);
	NcursesTool::drawText(display, b, v, "Dossier personnel : " +
		_homePath + " ");
	v.setY(60);
	NcursesTool::drawText(display, b, v, "Shell par defaut : " +
		_defaultShell + " ");
	v.setY(75);
	NcursesTool::drawText(display, b, v, "Nom d'hote : " +
		_hostName + " ");
}

bool UserModule::render(NcursesDisplay &display) const
{
	if (!show)
		return false;
	Box b = calcAbsSizeTerm(getBox());
	NcursesTool::drawBox(display, b, "Utilisateur");
	Vec v(10, 15);
	NcursesTool::drawText(display, b, v,
	                      "Utilisateur courant : " + _username + " ");
	v.setY(30);
	std::stringstream s;
	s << _uid << "/" << _sid;
	NcursesTool::drawText(display, b, v, "UID/SID : " +
	s.str() + " ");
	render_Ncurse(display, b, v);
	return true;
}

std::string UserModule::buildLabels(std::string &_str)
{
	_str += "<span size =\"large\">Shell par défaut</span>: <span "
	        "size=\"x-large\"><b>";
	_str += _defaultShell.c_str();
	_str += "</b></span>\n<span size=\"large\">Nom d'hôte</span>: <span "
	        "size=\"x-large\"><b>";
	_str += _hostName.c_str();
	_str += "</b></span>\n";
	return _str;
}

bool UserModule::render(GTKDisplay &display) const
{
	if (!display.isIn(this)) {
		display.addToDisplay(this, _frame, getBox().getX() + 1,
		                     getBox().getY() + 1);
	}
	std::stringstream s;
	s << _uid << "/" << _sid;
	std::string _str = "<span size=\"large\">Utilisateur courant</span>: "
	                   "<span size=\"x-large\"><b>";
	_str += _username.c_str();
	_str += "</b></span>\n<span size=\"large\">UID/SID</span>: <span "
	        "size=\"x-large\"><b>";
	_str += s.str().c_str();
	_str += "</b></span>\n<span size=\"large\">Dossier personnel</span>: "
	        "<span size=\"x-large\"><b>";
	_str += _homePath.c_str();
	_str += "</b></span>\n";
	gtk_label_set_use_markup(GTK_LABEL(_label), TRUE);
	gtk_label_set_markup(GTK_LABEL(_label), _str.c_str());
	return false;
}

bool UserModule::setup()
{
	if (this->_loaded == false) {
		_frame = gtk_frame_new("User Module");
		gtk_widget_set_size_request(
		    GTK_WIDGET(_frame), (getBox().getWidth() - 2) * 1280 / 100,
		    (getBox().getHeigth() - 2) * 720 / 100);
		_fixed = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(_frame), _fixed);
		_label = gtk_label_new("");
		gtk_fixed_put(GTK_FIXED(_fixed), _label, 10, 10);
		gtk_label_set_use_markup(GTK_LABEL(_label), TRUE);
	}
	return true;
}

bool UserModule::isShow() const
{
	return show;
}

void UserModule::event(int c)
{
	if (c == 'u')
		show = !show;
}
