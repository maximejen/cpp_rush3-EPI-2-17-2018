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

class IMonitorDisplay;

class IMonitorModule {
public:
	virtual const std::string &getType() const = 0;
	virtual bool render(IMonitorDisplay &display) const = 0;
	virtual void clear(IMonitorDisplay &display) const = 0;
	virtual bool getInfos() = 0;
};

#endif /* !CPP_RUSH3_IMONITORMODULE_HPP */
