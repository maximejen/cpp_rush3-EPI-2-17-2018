/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main.cpp
*/

#include <ModulePager.hpp>
#include "ncurses/NcursesDisplay.hpp"
#include "gtk/GTKDisplay.hpp"
#include "Parser.hpp"

int main(int argc, char **argv)
{
	Parser parser;
	ModulePager mp;
	gtk_init(&argc, &argv);
	mp.initModule();
	if (parser.ProcessArgs(argc, argv)) {
		gtk_init(&argc, &argv);
		GTKDisplay display;
		display.setup();
		display.render(mp);
		display.teardown();
	} else {
		NcursesDisplay display;
		display.setup();
		display.render(mp);
		display.teardown();
	}
}