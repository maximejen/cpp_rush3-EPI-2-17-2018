/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main.cpp
*/

#include <iostream>
#include "ncurses/NcursesDisplay.hpp"
#include "AMonitorModule.hpp"
#include "ncurses/tool/NcursesTool.hpp"

int main(int argc, char **argv)
{
	Box b(10, 10, 100, 31);
	NcursesDisplay display;
	display.setup();
	while (1) {
		display.render();
		sleep(1.5);
	}
	display.teardown();
}