/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** IMonitorDisplay.hpp
*/

#ifndef CPP_RUSH3_IMONITORDISPLAY_HPP
	#define CPP_RUSH3_IMONITORDISPLAY_HPP

	#include "IMonitorModule.hpp"

//TODO check avec le groupe

class IMonitorDisplay {
	virtual bool setup() = 0;
	virtual bool render() = 0;
	virtual bool clearRender() = 0;
	virtual bool refreshRender() = 0;
	virtual bool teardown() = 0;
};

#endif /* !CPP_RUSH3_IMONITORDISPLAY_HPP */
