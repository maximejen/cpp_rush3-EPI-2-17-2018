/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main.cpp
*/

#include "ncurses/NcursesDisplay.hpp"

int main()
{
	NcursesDisplay display;
	display.setup();
	display.render();
	display.teardown();
}