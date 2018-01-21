/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesTool.cpp
*/

#include "NcursesTool.hpp"
#include <iostream>
#include <unordered_map>

NcursesTool::NcursesTool(NcursesDisplay &disp, Box const &box)
: _disp(disp), _box(box)
{
}

bool NcursesTool::isIn(size_t a, size_t rA, size_t rB)
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
	(void) disp;
	std::string t(title);
	size_t xTitle;
	for (size_t y = b.getY(); y < b.getAbsoluteH(); y++)
		for (size_t x = b.getX(); x < b.getAbsoluteW(); x++)
			drawPointBox(disp, b, x, y);
	if (t != "") {
		t = "[" + t + "]";
		if (t.size() >= b.getWidth() - 2)
			t = "[.]";
		xTitle =
		static_cast<size_t>((b.getWidth() / 2) - (t.length() / 2));
		mvprintw(b.getY(), b.getX() + xTitle, "%s", t.c_str());
	}
}

void NcursesTool::drawPointBox(NcursesDisplay const &disp, Box const &b,
size_t x, size_t y)
{
	(void)disp;
	std::map<std::pair<size_t, size_t>, int> map = {
	{std::pair<size_t, size_t>
	 (b.getX(), b.getY()),                         ACS_ULCORNER},
	{std::pair<size_t, size_t>
	 (b.getAbsoluteW() - 1, b.getY()),             ACS_URCORNER},
	{std::pair<size_t, size_t>
	 (b.getX(), b.getAbsoluteH() - 1),             ACS_LLCORNER},
	{std::pair<size_t, size_t>
	 (b.getAbsoluteW() - 1, b.getAbsoluteH() - 1), ACS_LRCORNER}
	};

	std::pair<size_t, size_t> vec(x, y);
	auto it = map.find(vec);
	if (it != map.end())
		mvaddch(y, x, map[vec]);
	else if (y == b.getY() || y == b.getAbsoluteH() - 1)
		mvaddch(y, x, ACS_HLINE);
	else if (x == b.getX() || x == b.getAbsoluteW() - 1)
		mvaddch(y, x, ACS_VLINE);
}

void NcursesTool::drawText(NcursesDisplay const &disp, Box const &b,
Vec const &v, const std::string &text)
{
	std::string t(text);

	(void) disp;
	if (!isIn(v.getX(), 0, 100) || !isIn(v.getY(), 0, 100))
		return;
	auto pos = calcCoordinate(b, v);
	if (pos.getX() + 1 + text.length() >= b.getWidth())
		t = t.substr(0, text.length() -
				(pos.getX() + 2 + text.length() -
				 b.getWidth()));
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
	(void) disp;
	if (!isIn(p.pos.getX()) || !isIn(p.pos.getY()) || !isIn(p.width) ||
	    !isIn(p.value))
		return;
	auto pos = calcCoordinate(b, p.pos);
	auto lenTot = static_cast<size_t>(
	p.width * (static_cast<float>(b.getWidth()) / 100.0));
	if (pos.getX() + lenTot >= b.getWidth() - 2)
		lenTot -= (pos.getX() + lenTot + 1) - (b.getWidth() - 2);
	auto len =
	static_cast<size_t>(lenTot * (static_cast<float>(p.value) / 100));
	for (size_t i = 0; i <= lenTot; i++)
		mvprintw(b.getY() + 1 + pos.getY(),
			 b.getX() + 1 + pos.getX() + i, (i <= len) ? "#" : " ");
	mvprintw(b.getY() + 1 + pos.getY(), b.getX() + 1 + pos.getX(), "[");
	mvprintw(b.getY() + 1 + pos.getY(), b.getX() + 1 + pos.getX() + lenTot,
		 "]");
}

void NcursesTool::drawPercent(Percent &p)
{
	drawPercent(_disp, _box, p);
}

Box NcursesTool::drawHistoBox(NcursesDisplay const &disp, Box const &b,
Histo const &h)
{
	(void) disp;
	Vec pRel(h.box.getX(), h.box.getY());
	Vec pAbs = calcCoordinate(b, pRel, 0);
	auto width = static_cast<int>(
	b.getWidth() * (static_cast<float>(h.box.getWidth()) / 100));
	auto height = static_cast<int>(
	b.getHeigth() * (static_cast<float>(h.box.getHeigth()) / 100));
	Box box(b.getX() + pAbs.getX(), b.getY() + pAbs.getY(), width, height);
	drawBox(disp, box, h.title);
	return box;
}

void NcursesTool::drawHisto(NcursesDisplay const &disp, Box const &b,
Histo &h)
{
	if (!isIn(h.box.getX()) || !isIn(h.box.getY()))
		return;
	size_t i = 0;
	int j = static_cast<int>(h.data.size()) - 1;
	Box box = drawHistoBox(disp, b, h);
	while (j >= 0 && i < box.getWidth() - 2) {
		drawLineHist(box.getAbsoluteW() - 2 - i,
			     box.getAbsoluteH() - 2, box, h.data[j]);
		j--;
		i += 1;
	}
	if (j > 0)
		h.data.erase(h.data.begin(), h.data.begin() + j);
}

void NcursesTool::drawLineHist(size_t x, size_t y, Box const &b, int value)
{
	auto height = static_cast<size_t>((b.getHeigth() - 3) *
					static_cast<float>(value) / 100);
	for (size_t i = 0; i <= b.getHeigth() - 3; i++)
		if (i <= height)
			mvprintw(static_cast<int>(y - i),
				static_cast<int>(x), "#");
		else
			mvprintw(static_cast<int>(y - i),
				static_cast<int>(x), " ");
}

Percent::Percent(size_t x, size_t y, size_t width, size_t value)
: pos(x, y), width(width), value(value)
{
}

Histo::Histo(size_t x, size_t y, size_t width, size_t height,
std::vector<int> &data, std::string const &title)
: box(x, y, width, height), data(data), title(title)
{
}
