/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main.cpp
*/

#include "ncurses/NcursesDisplay.hpp"
#include "AMonitorModule.hpp"
#include "ncurses/tool/NcursesTool.hpp"

int main(int argc, char **argv)
{
	Box b(10, 10, 100, 31);
	NcursesDisplay display;
	display.setup();
	NcursesTool::drawBox(display, b, "123456");
	Vec v(0, 0);
	NcursesTool::drawText(display, b, v, "lol");
	Vec v1(50, 100);
	Percent p(10, 50, 80, 50);
	NcursesTool::drawText(display, b, v1, "lol c'est vraiment une phrase qui est très longue et qui ne rentre pas sur un écran");
//	NcursesTool::drawPercent(display, b, p);
	std::vector<int> vector;
	vector.push_back(50);
	vector.push_back(75);
	vector.push_back(100);
	vector.push_back(25);
	vector.push_back(10);
	Histo h(10, 10, 80, 80, vector, "CPU 1");
	NcursesTool::drawHisto(display, b, h);

	Box b2(109, 10, 11, 10);
	NcursesTool t(display, b2);
	t.drawBox("mdr");
	t.drawText(v1, "lol");
	Percent p2(0, 50, 100, 25);
	t.drawPercent(p2);
	display.render();
	display.teardown();
//	display.setup();
//	display.render();
//	display.teardown();
}