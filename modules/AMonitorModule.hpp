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
	Vec(int x, int y);
	int getX() const;
	int getY() const;
	void setXY(int x, int y);
	void setX(int x);
	void setY(int y);

private:
	int x;
	int y;
};

class Box {
public:
	Box(int x, int y, int width, int heigth);
	int getX() const;
	int getY() const;
	int getAbsoluteW() const;
	int getAbsoluteH() const;
	int getWidth() const;
	int getHeigth() const;
private:
	int x;
	int y;
	int width;
	int heigth;
};

class AMonitorModule : public IMonitorModule {
public:
	AMonitorModule(const std::string &_type, int x, int y, int w, int h);
	AMonitorModule(const std::string &_type, const Box &box);
	virtual const std::string &getType() const;
	virtual bool render(NcursesDisplay &display) const = 0;
	virtual bool render(GTKDisplay &display) const = 0;
	virtual void clear(NcursesDisplay &display) const;
	virtual void clear(GTKDisplay &display) const;
	virtual bool getInfos();
	virtual const Box &getBox() const;
protected:
	std::string _type;
	Box _box;
};


#endif /* !CPP_RUSH3_AMONITORMODULE_HPP */
