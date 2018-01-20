/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesDisplay.hpp
*/

#ifndef CPP_RUSH3_NCURSESDISPLAY_HPP
	#define CPP_RUSH3_NCURSESDISPLAY_HPP

	#include "IMonitorDisplay.hpp"

class NcursesDisplay : IMonitorDisplay {
public:
	NcursesDisplay();
	bool setup() override;
	bool render() override;
	bool clear() override;
	bool teardown() override;
};


#endif /* !CPP_RUSH3_NCURSESDISPLAY_HPP */
