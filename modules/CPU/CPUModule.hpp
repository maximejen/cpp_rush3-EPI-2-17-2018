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
	bool setup() override;
	void event(int c) override;

private:
	bool get_next_cpu(std::ifstream &, size_t index);
	void printInfoCPU(NcursesDisplay &d, Box const &abs,
	Box const &b) const;
	void getModel();
	void getFrequence();
	size_t cpu;
	size_t histoIdx;
	GtkWidget *_frame;
	GtkWidget *_fixed;
	GtkWidget *_label;
	std::vector<std::vector<double>> histo;
	std::vector<float> previous_idle;
	std::vector<float> previous_total;
	std::string model;
	std::string frequence;
};

#endif /* !CPP_RUSH3_CPUMODULE_HPP */
