/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** PCModule.hpp
*/

#ifndef CPP_RUSH3_PCMODULE_HPP
	#define CPP_RUSH3_PCMODULE_HPP

	#include <AMonitorModule.hpp>
	#include "AMonitorModule.hpp"
	#include "gtk/GTKDisplay.hpp"
	#include "ncurses/NcursesDisplay.hpp"

class PCModule : public AMonitorModule {
public:
	PCModule(int x, int y, int w, int h);
	explicit PCModule(const Box &box);
	bool render(NcursesDisplay &display) const override;
	bool render(GTKDisplay &display) const override;
	void clear(NcursesDisplay &display) const override;
	void clear(GTKDisplay &display) const override;
	bool getInfos() override;
private:
	std::string _kernel;
	std::string _os;
};


#endif /* !CPP_RUSH3_PCMODULE_HPP */
