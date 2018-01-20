/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** AMonitorModule.hpp
*/

#ifndef CPP_RUSH3_AMONITORMODULE_HPP
	#define CPP_RUSH3_AMONITORMODULE_HPP

	#include "IMonitorModule.hpp"
	#include "gtk/GTKDisplay.hpp"
	#include "ncurses/NcursesDisplay.hpp"

class GTKDisplay;
class NcursesDisplay;

class Vec {
public:
	Vec(size_t x, size_t y);
	size_t getX() const;
	size_t getY() const;
	void setXY(size_t x, size_t y);
	void setX(size_t x);
	void setY(size_t y);

private:
	size_t x;
	size_t y;
};

class Box {
public:
	Box(size_t x, size_t y, size_t width, size_t heigth);
	size_t getX() const;
	size_t getY() const;
	size_t getAbsoluteW() const;
	size_t getAbsoluteH() const;
	size_t getWidth() const;
	size_t getHeigth() const;
private:
	size_t x;
	size_t y;
	size_t width;
	size_t heigth;
};

class AMonitorModule : public IMonitorModule {
public:
	AMonitorModule(const std::string &_type, int x, int y, int w, int h);
	AMonitorModule(const std::string &_type, const Box &box);
	virtual ~AMonitorModule();
	virtual const std::string &getType() const;
	virtual bool render(NcursesDisplay &display) const = 0;
	virtual bool render(GTKDisplay &display) const = 0;
	virtual void clear(NcursesDisplay &display) const;
	virtual void clear(GTKDisplay &display) const;
	virtual bool setup();
	virtual const Box &getBox() const;
protected:
	std::string _type;
	Box _box;
};


#endif /* !CPP_RUSH3_AMONITORMODULE_HPP */
