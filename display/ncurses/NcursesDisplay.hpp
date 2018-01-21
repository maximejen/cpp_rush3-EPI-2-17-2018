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
	#include "ModulePager.hpp"
	#include "AMonitorModule.hpp"
	#include "IMonitorDisplay.hpp"

class IMonitorModule;
class AMonitorModule;

class NcursesDisplay : public IMonitorDisplay {
public:
	NcursesDisplay();
	virtual ~NcursesDisplay();
	bool setup();
	bool render(ModulePager &mp);
	bool event(ModulePager &mp, int c);
	bool refreshRender();
	bool teardown();
	bool clearRender();
	void printPageInfo(ModulePager const &mp);
	WINDOW *getWindow() const;

private:
	WINDOW *_mainwin;
//	std::vector<AMonitorModule *> _modules;
};

#endif /* !CPP_RUSH3_NCURSESDISPLAY_HPP */
