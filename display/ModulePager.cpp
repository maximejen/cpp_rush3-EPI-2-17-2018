/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** ModulePager.cpp
*/

#include "time/TimeModule.hpp"
#include "CPU/CPUModule.hpp"
#include "ModulePager.hpp"

ModulePager::ModulePager(): _currentPage(0)
{
}

void ModulePager::addPage(std::string const &name,
std::vector<AMonitorModule *> modules)
{
	Page p(name, modules);
	_pages.push_back(p);
}

Page::Page(std::string const &name, std::vector<AMonitorModule *> modules) :
name(name), module(modules)
{
}

void ModulePager::initModule()
{
	std::vector<AMonitorModule *> modGeneral;
	modGeneral.push_back(new TimeModule(0, 0, 100, 100));
	addPage("Informations generales", modGeneral);
	std::vector<AMonitorModule *> modCPU;
	addPage("Informations processeurs", modCPU);
}

void ModulePager::inc()
{
	if (static_cast<size_t>(_currentPage) >= _pages.size() - 1)
		_currentPage = -1;
	_currentPage += 1;
}

void ModulePager::dec()
{
	if (_currentPage == 0)
		_currentPage = static_cast<int>(_pages.size() - 1);
	else
		_currentPage -= 1;
}

Page ModulePager::getCurPage() const
{
	return _pages[_currentPage];
}

ModulePager::~ModulePager()
{
	for (auto &i : _pages)
		for (auto &d : i.module)
			delete(d);
}
