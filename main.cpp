/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main.cpp
*/

#include "ncurses/NcursesDisplay.hpp"
#include "gtk/GTKDisplay.hpp"
#include "Parser.hpp"

int main(int argc, char **argv)
{
	Parser parser;
	gtk_init(&argc, &argv);
	if (parser.ProcessArgs(argc, argv)) {
		GTKDisplay display;
		display.setup();
		display.render();
		display.teardown();
	} else {
		NcursesDisplay display;
		display.setup();
		display.render();
		display.teardown();
	}
}