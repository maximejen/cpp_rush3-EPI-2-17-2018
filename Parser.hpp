/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** Parser.hpp
*/

#ifndef CPP_RUSH3_PARSER_HPP
	#define CPP_RUSH3_PARSER_HPP


class Parser {
public:
	Parser() = default;
	void PrintHelp(bool error);
	bool ProcessArgs(int argc, char **argv);
};


#endif /* !CPP_RUSH3_PARSER_HPP */
