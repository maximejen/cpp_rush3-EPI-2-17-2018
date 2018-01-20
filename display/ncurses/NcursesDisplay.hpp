/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesDisplay.hpp
*/

#ifndef CPP_RUSH3_NCURSESDISPLAY_HPP
	#define CPP_RUSH3_NCURSESDISPLAY_HPP

	#include <ncurses.h>
	#include <vector>
	#include <map>
	#include "AMonitorModule.hpp"
	#include "IMonitorDisplay.hpp"

class IMonitorModule;
class AMonitorModule;

class NcursesDisplay : public IMonitorDisplay {
public:
	NcursesDisplay();
	virtual ~NcursesDisplay();
	bool setup();
	bool render();
	bool refreshRender();
	bool teardown();
	bool clearRender();
	WINDOW *getWindow() const;
private:
	WINDOW *_mainwin;
	std::vector<AMonitorModule *> _modules;
};

#endif /* !CPP_RUSH3_NCURSESDISPLAY_HPP */
