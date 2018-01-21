/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NetworkModule.hpp
*/

#ifndef CPP_RUSH3_NETWORKMODULE_HPP
	#define CPP_RUSH3_NETWORKMODULE_HPP

	#include <map>
	#include <regex>
	#include "AMonitorModule.hpp"
	#include "IMonitorDisplay.hpp"

class NetworkModule : public AMonitorModule {
public:
	explicit NetworkModule(int x, int y, int w, int h);
	~NetworkModule();
	virtual bool render(NcursesDisplay &display) const;
	virtual bool render(GTKDisplay &display) const;
	bool setup();
private:
	bool setup_connexions(const std::string &,
		const std::string &);
	std::string networkFile;
	std::map<std::string, std::vector<unsigned long long int>[2]>
		connexions;
	std::map<std::string, unsigned long long int [2]> max;
	std::vector<int> normalize_network(std::vector<unsigned long long>,
		unsigned long long int max) const;
	void normalize_max(std::vector<unsigned long long>,
		unsigned long long int &max);
};


#endif /* !CPP_RUSH3_NETWORKMODULE_HPP */
