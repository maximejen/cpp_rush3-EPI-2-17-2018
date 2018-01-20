/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** TimeModule.hpp
*/

#ifndef CPP_RUSH3_TIMEMODULE_HPP
	#define CPP_RUSH3_TIMEMODULE_HPP

	#include <glob.h>
	#include <string>
	#include <AMonitorModule.hpp>

class TimeModule : public AMonitorModule {
public:
	TimeModule();
	std::string getUpTime() const;
	std::string getDate() const;

private:
	const std::string uptimeFile = "/proc/uptime";
};

#endif /* !CPP_RUSH3_TIMEMODULE_HPP */
