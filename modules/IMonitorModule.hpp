/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** IMonitorModule.hpp
*/

#ifndef CPP_RUSH3_IMONITORMODULE_HPP
	#define CPP_RUSH3_IMONITORMODULE_HPP

	#include <string>

//TODO check avec le groupe

class NcursesDisplay;
class GTKDisplay;

class IMonitorModule {
public:
	virtual const std::string &getType() const = 0;
	virtual bool render(NcursesDisplay &display) const = 0;
	virtual bool render(GTKDisplay &display) const = 0;
	virtual void clear(NcursesDisplay &display) const = 0;
	virtual void clear(GTKDisplay &display) const = 0;
	virtual bool getInfos() = 0;
};

#endif /* !CPP_RUSH3_IMONITORMODULE_HPP */
