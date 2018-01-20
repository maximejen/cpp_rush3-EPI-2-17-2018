/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesTool.cpp
*/

#include <iostream>
#include "NcursesTool.hpp"

NcursesTool::NcursesTool(NcursesDisplay &disp, Box const &box) :
_disp(disp), _box(box)
{
}

bool NcursesTool::isIn(int a, int rA, int rB)
{
	return (rA <= a && a <= rB);
}

Vec NcursesTool::calcCoordinate(Box const &b, Vec const &v, int shift)
{
	auto xPer = static_cast<float>(v.getX()) / 100;
	auto yPer = static_cast<float>(v.getY()) / 100;
	auto xAbs = static_cast<int>((b.getWidth() - shift) * xPer);
	auto yAbs = static_cast<int>((b.getHeigth() - shift) * yPer);
	return Vec(xAbs, yAbs);
}

void NcursesTool::drawBox(NcursesDisplay const &disp, Box const &b,
std::string const &title)
{
	std::string t(title);
	int xTitle;
	for (int y = b.getY(); y < b.getAbsoluteH(); y++)
		for (int x = b.getX(); x < b.getAbsoluteW(); x++)
			drawPointBox(disp, b, x, y);
	if (t != "") {
		t = "[" + t + "]";
		if (t.size() >= b.getWidth() - 2)
			t = "[.]";
		xTitle = static_cast<int>
		((b.getWidth() / 2) - (t.length() / 2));
		mvprintw(b.getY(), b.getX() + xTitle, "%s", t.c_str());
	}
}

void NcursesTool::drawPointBox(NcursesDisplay const &disp, Box const &b, int x,
int y)
{
	if ((x == b.getX() && y == b.getY()) ||
	    (x == b.getAbsoluteW() - 1 && y == b.getAbsoluteH() - 1) ||
	    (x == b.getX() && y == b.getAbsoluteH() - 1) ||
	    (x == b.getAbsoluteW() - 1 && y == b.getY()))
		mvprintw(y, x, "+");
	else if (y == b.getY() || y == b.getAbsoluteH() - 1)
		mvprintw(y, x, "-");
	else if (x == b.getX() || x == b.getAbsoluteW() - 1)
		mvprintw(y, x, "|");
}

void NcursesTool::drawText(NcursesDisplay const &disp, Box const &b,
Vec const &v, const std::string &text)
{
	std::string t(text);

	if (!isIn(v.getX(), 0, 100) || !isIn(v.getY(), 0, 100))
		return;
	auto pos = calcCoordinate(b, v);
	if (pos.getX() + 1 + text.length() >= b.getWidth())
		t = t.substr(0, text.length() -
		(pos.getX() + 2 + text.length() - b.getWidth()));
	else
		t = t.substr(0, text.length() - 1);
	mvprintw(b.getY() + pos.getY() + 1,
		b.getX() + pos.getX() + 1, "%s", t.c_str());
}

void NcursesTool::drawBox(const std::string &title)
{
	NcursesTool::drawBox(_disp, _box, title);
}

void NcursesTool::drawText(Vec const &v, std::string const &text)
{
	NcursesTool::drawText(_disp, _box, v, text);
}

void NcursesTool::drawPercent(NcursesDisplay const &disp, Box const &b,
Percent &p)
{
	if (!isIn(p.pos.getX()) || !isIn(p.pos.getY()) ||
	!isIn(p.width) || !isIn(p.value))
		return;
	auto pos = calcCoordinate(b, p.pos);
	auto lenTot = static_cast<int>(p.width *
		(static_cast<float>(b.getWidth()) / 100));
	if (pos.getX() + lenTot >= b.getWidth() - 2)
		lenTot -= (pos.getX() + lenTot + 1) - (b.getWidth() - 2);
	auto len = static_cast<int>(lenTot *
		(static_cast<float>(p.value) / 100));
	for (int i = 0; i <= lenTot; i++)
		if (i <= len)
			mvprintw(b.getY() + 1 + pos.getY(),
				 b.getX() + 1 + pos.getX() + i, "#");
		else
			mvprintw(b.getY() + 1 + pos.getY(),
				 b.getX() + 1 + pos.getX() + i, " ");
	mvprintw(b.getY() + 1 + pos.getY(), b.getX() + 1 + pos.getX(), "[");
	mvprintw(b.getY() + 1 + pos.getY(),
		 b.getX() + 1 + pos.getX() + lenTot, "]");
}

void NcursesTool::drawPercent(Percent &p)
{
	drawPercent(_disp, _box, p);
}

Box NcursesTool::drawHistoBox(NcursesDisplay const &disp, Box const &b,
Histo const &h)
{
	Vec pRel(h.box.getX(), h.box.getY());
	Vec pAbs = calcCoordinate(b, pRel, 0);
	auto width = static_cast<int>(b.getWidth() *
		(static_cast<float>(h.box.getWidth()) / 100));
	auto height = static_cast<int>(b.getHeigth() *
		(static_cast<float>(h.box.getHeigth()) / 100));
	Box box(b.getX() + pAbs.getX(), b.getY() + pAbs.getY(), width, height);
	drawBox(disp, box, h.title);
	return box;
}

void NcursesTool::drawHisto(NcursesDisplay const &disp, Box const &b,
Histo &h)
{
	if (!isIn(h.box.getX()) || !isIn(h.box.getY()))
		return;
	int i = 0;
	int j = static_cast<int>(h.data.size()) - 1;
	Box box = drawHistoBox(disp, b, h);
	while (j >= 0 && i < box.getWidth()) {
		drawLineHist(box.getAbsoluteW() - 2 - i,
		box.getAbsoluteH() - 2, box, h.data[j]);
		j--;
		i += 1;
	}
	h.data.erase(h.data.begin(), h.data.begin() + j);
}

void NcursesTool::drawLineHist(int x, int y, Box const &b, int value)
{
	auto height = static_cast<int>((b.getHeigth() - 3) *
		static_cast<float>(value) / 100);
	for (int i = 0; i <= b.getHeigth() - 3; i++)
		if (i <= height)
			mvprintw(y - i, x, "#");
		else
			mvprintw(y - i, x, " ");
}

Percent::Percent(int x, int y, int width, int value) :
pos(x, y), width(width), value(value)
{
}

Histo::Histo(int x, int y, int width, int height, std::vector<int> &data,
std::string const &title) :
box(x, y, width, height), data(data), title(title)
{
}
