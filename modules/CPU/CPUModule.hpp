/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** CPUModule.hpp
*/

#ifndef CPP_RUSH3_CPUMODULE_HPP
	#define CPP_RUSH3_CPUMODULE_HPP

	#include <fstream>
	#include "AMonitorModule.hpp"
	#include "gtk/GTKDisplay.hpp"
	#include "ncurses/NcursesDisplay.hpp"

class CPUModule : public AMonitorModule {
public:
	CPUModule(int x, int y, int w, int h);
	explicit CPUModule(const Box &box);
	bool render(NcursesDisplay &display) const override;
	bool render(GTKDisplay &display) const override;
	void clear(NcursesDisplay &display) const override;
	void clear(GTKDisplay &display) const override;
	bool getInfos() override;
private:
	bool get_next_cpu(std::ifstream &, int index);
	size_t cpu;
	size_t histo_idx;
	std::vector<std::vector<double>> histo;
	std::vector<float> previous_idle;
	std::vector<float> previous_total;
};


#endif /* !CPP_RUSH3_CPUMODULE_HPP */