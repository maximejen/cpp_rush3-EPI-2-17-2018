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

void PrintHelp()
{
	std::cout
		<< "--num <n>:           Set number of program\n" << std::end
		<< "--beep:              Beep the user\n" << std::end
		<< "--sigma <val>:       Set sigma of program\n" << std::end
		<< "--writeFile <fname>: File to write to\n" << std::end
		<< "--help:              Show help" << std::end;
	exit(1);
}

void ProcessArgs(int argc, char **argv)
{
	const char *const short_opts = "n:bs:w:h";
	const option long_opts[] = {
		{"num",       1, nullptr, 'n'},
		{"beep",      0, nullptr, 'b'},
		{"sigma",     1, nullptr, 's'},
		{"writeFile", 1, nullptr, 'w'},
		{"help",      0, nullptr, 'h'},
		{nullptr,     0, nullptr, 0}
	};

	while (true) {
		const auto opt = getopt_long(argc, argv, short_opts, long_opts,
		                             nullptr);

		if (-1 == opt)
			break;

		switch (opt) {
			case 'n':
				num = std::stoi(optarg);
				std::cout << "Num set to: " << num << std::endl;
				break;

			case 'b':
				is_beep = true;
				std::cout << "Beep is set to true\n";
				break;

			case 's':
				sigma = std::stof(optarg);
				std::cout << "Sigma set to: " << sigma
				          << std::endl;
				break;

			case 'w':
				write_file = std::string(optarg);
				std::cout << "Write file set to: " << write_file
				          << std::endl;
				break;

			case 'h': // -h or --help
			case '?': // Unrecognized option
			default:
				PrintHelp();
				break;
		}
	}
}

int main(int argc, char **argv)
{

}