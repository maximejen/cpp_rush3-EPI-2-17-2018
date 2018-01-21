/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** ModulePager.hpp
*/

#ifndef CPP_RUSH3_MODULEPAGER_HPP
	#define CPP_RUSH3_MODULEPAGER_HPP

	#include <vector>
	#include <string>

class IMonitorModule;
class AMonitorModule;

struct Page {
	Page() = default;
	Page(std::string const &name, std::vector<AMonitorModule *> modules);
	std::string const name;
	std::vector<AMonitorModule *> module;
};

class ModulePager {
public:
	ModulePager();
	~ModulePager();
	void addPage(std::string const &name,
	std::vector<AMonitorModule *> modules);
	void initModule();
	Page getCurPage() const;
	void inc();
	void dec();

private:
	std::vector<Page> _pages;
	int _currentPage;
};

#endif /* !CPP_RUSH3_MODULEPAGER_HPP */
