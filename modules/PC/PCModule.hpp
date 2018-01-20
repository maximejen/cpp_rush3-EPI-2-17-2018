/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** PCModule.hpp
*/

#ifndef CPP_RUSH3_PCMODULE_HPP
	#define CPP_RUSH3_PCMODULE_HPP

	#include "ncurses/NcursesDisplay.hpp"
	#include "AMonitorModule.hpp"

class PCModule : public AMonitorModule {
public:
	PCModule(int x, int y, int w, int h);
	explicit PCModule(const Box &box);
	bool render(IMonitorDisplay &display) const override;
	//bool render(NcursesDisplay &display) const;
	void clear(IMonitorDisplay &display) const override;
	bool getInfos() override;
private:
	std::string hostname;
	std::string kernel;
	std::string os;
};


#endif /* !CPP_RUSH3_PCMODULE_HPP */
