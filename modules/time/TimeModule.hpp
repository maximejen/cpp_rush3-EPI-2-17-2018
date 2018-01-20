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
	std::string getUpTime() const;
	std::string getDate() const;
	bool render(NcursesDisplay &display) const override;
	bool render(GTKDisplay &display) const override;
	void clear(NcursesDisplay &display) const override;
	void clear(GTKDisplay &display) const override;
	bool setup() override;
	void event(char c) override;

private:
	const std::string uptimeFile = "/proc/uptime";
	GtkWidget *_frame;
	GtkWidget *_fixed;
	GtkWidget *_label;
	std::string _str;
	std::string _uptime;
	std::string _date;
	bool _show;
};

#endif /* !CPP_RUSH3_TIMEMODULE_HPP */
