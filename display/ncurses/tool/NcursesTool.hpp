/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesTool.hpp
*/

#ifndef CPP_RUSH3_NCURSESTOOL_HPP
	#define CPP_RUSH3_NCURSESTOOL_HPP

	#include <string>
	#include <vector>
	#include "AMonitorModule.hpp"
	#include "ncurses/NcursesDisplay.hpp"

struct Percent {
	Percent() = default;
	Percent(int x, int y, int width, int value);
	Vec pos;
	int width;
	int value;
};

struct Histo {
	Histo() = default;
	Histo(int x, int y, int width, int height, std::vector<int> &data,
		std::string const &name = "");
	Box box;
	std::vector<int> data;
	std::string const title;
};

class NcursesTool {
public:
	NcursesTool(NcursesDisplay &disp, Box const &box);

	static void drawBox(NcursesDisplay const &disp, Box const &b,
		std::string const &title = "");
	void drawBox(std::string const &title = "");

	static void drawText(NcursesDisplay const &disp, Box const &b,
		Vec const &v, std::string const &text);
	void drawText(Vec const &v, std::string const &text);

	static void drawPercent(NcursesDisplay const &disp, Box const &b,
		Percent &p);
	void drawPercent(Percent &p);

	static void drawHisto(NcursesDisplay const &disp, Box const &b,
		Histo const &h);

private:
	static void drawPointBox(NcursesDisplay const &disp,
		Box const &b, int x, int y);
	static Box drawHistoBox(NcursesDisplay const &disp,
		Box const &b, Histo const &h);
	static void drawLineHist(int x, int y, Box const &b, int value);
	static bool isIn(int a, int rA = 0, int rB = 100);
	static Vec calcCoordinate(Box const &b, Vec const &v, int shift = 3);
	NcursesDisplay &_disp;
	Box const _box;
};

#endif /* !CPP_RUSH3_NCURSESTOOL_HPP */