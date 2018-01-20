/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** Parser.cpp
*/

#include <cstdlib>
#include <iostream>
#include "Parser.hpp"


void Parser::PrintHelp(bool error)
{
	std::cout
		<< "Help : " << std::endl
		<< "\t--graph: Display the graphical mode" << std::endl
		<< "\t--help: Show help" << std::endl;
	if (error)
		exit(84);
	else
		exit(0);
}

bool Parser::ProcessArgs(int argc, char **argv)
{
	auto out = false;
	for (int i = 1; i < argc ; i++) {
		if (std::string(argv[i]) == "--graph")
			out = true;
		else
			PrintHelp(std::string(argv[i]) != "--help");
	}
	return out;
}

