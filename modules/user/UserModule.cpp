/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** UserModule.cpp
*/

#include <zconf.h>
#include <iostream>
#include <grp.h>
#include <pwd.h>
#include "UserModule.hpp"

UserModule::UserModule(int x, int y, int w, int h)
: AMonitorModule("UserModule", x, y, w, h), _username(getlogin()), _uid(getuid())
{
	int ngroups = 100;
	gid_t groups[10];
	char hostName[1024];

	getgrouplist(this->_username.c_str(), 0, groups, &ngroups);
	for (int i = 0 ; i < ngroups ; i++) {
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

bool UserModule::render(NcursesDisplay &display) const
{
	(void)display;
	return false;
}

bool UserModule::render(GTKDisplay &display) const
{
	(void)display;
	return false;
}
