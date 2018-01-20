/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** UserModule.hpp
*/

#ifndef CPP_RUSH3_USERMODULE_HPP
	#define CPP_RUSH3_USERMODULE_HPP

	#include <string>
	#include <AMonitorModule.hpp>
	#include <vector>

class UserModule : public AMonitorModule {
public:
	UserModule(int x, int y, int w, int h);
	~UserModule();
	const std::string &getUsername() const;
	int getUid() const;
	const std::string &getDefaultShell() const;
	const std::string &getHomePath() const;
	const std::vector<std::string> &getGroupNames() const;
	const std::vector<gid_t> &getGroupGID() const;
	int getSid() const;
	const std::string &getHostName() const;
	virtual bool render(NcursesDisplay &display) const;
	virtual bool render(GTKDisplay &display) const;

private:
	std::string _username;
	int _uid;
	std::vector<gid_t> _groupGID;
	std::vector<std::string> _groupNames;
	int _sid;
	std::string _homePath;
	std::string _defaultShell;
	std::string _hostName;
};


#endif /* !CPP_RUSH3_USERMODULE_HPP */
