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
	TimeModule(int x, int y, int w, int h);
	bool render(GTKDisplay &display) const override;
	bool render(NcursesDisplay &display) const override;
	std::string getUpTime() const;
	std::string getDate() const;
	bool getInfos() override;

private:
	const std::string uptimeFile = "/proc/uptime";
	std::string uptime;
	std::string date;
};

#endif /* !CPP_RUSH3_TIMEMODULE_HPP */
