/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main.cpp
*/

#include "ncurses/NcursesDisplay.hpp"
#include "PC/PCModule.hpp"
#include "gtk/GTKDisplay.hpp"

int main(int argc, char **argv)
{
        gtk_init(&argc, (char ***)&argv);
	auto display = new GTKDisplay();
	display->setup();
	display->render();
	display->teardown();
}