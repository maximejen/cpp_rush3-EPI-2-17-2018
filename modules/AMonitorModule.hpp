/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** AMonitorModule.hpp
*/

#ifndef CPP_RUSH3_AMONITORMODULE_HPP
	#define CPP_RUSH3_AMONITORMODULE_HPP

	#include "IMonitorModule.hpp"

class AMonitorModule : IMonitorModule {
public:
	explicit AMonitorModule(const std::string &_type);
	const std::string &getType() const override;
	bool render(IMonitorDisplay &display) const override;
	void clear(IMonitorDisplay &display) const override;
	bool getInfos() override;
private:
	std::string _type;
};


#endif /* !CPP_RUSH3_AMONITORMODULE_HPP */
