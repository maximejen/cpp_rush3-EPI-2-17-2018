/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main.cpp
*/

#include "AMonitorModule.hpp"
#include "ncurses/NcursesDisplay.hpp"
#include "ncurses/tool/NcursesTool.hpp"
#include <iostream>
#include <thread>

int main(int argc, char **argv)
{
        gtk_init(&argc, (char ***)&argv);
        auto display = new GTKDisplay();
        display->setup();
        while (1)
                display->render();
        display->teardown();
}