/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesDisplay.hpp
*/

#ifndef CPP_RUSH3_NCURSESDISPLAY_HPP
	#define CPP_RUSH3_NCURSESDISPLAY_HPP

	#include <ncurses.h>
	#include "IMonitorDisplay.hpp"

class NcursesDisplay : IMonitorDisplay {
public:
	NcursesDisplay();
	bool setup() override;
	bool render() override;
	bool refresh() override;
	bool teardown() override;
private:
	WINDOW *_mainwin;
};


#endif /* !CPP_RUSH3_NCURSESDISPLAY_HPP */
