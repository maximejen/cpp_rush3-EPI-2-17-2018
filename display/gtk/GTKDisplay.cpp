/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "GTKDisplay.hpp"
#include "CPU/CPUModule.hpp"
#include "PC/PCModule.hpp"
#include <map>
#include <utility>

GTKDisplay::GTKDisplay()
{
	_tabsLoaded = false;
}

GTKDisplay::~GTKDisplay()
{
}

void GTKDisplay::quit()
{
	exit(0);
}

bool GTKDisplay::setup()
{
	_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(_window), "Rush 3");
	gtk_window_set_default_size(GTK_WINDOW(_window), 1280, 720);
	_tabs = gtk_notebook_new();
	gtk_window_set_resizable(GTK_WINDOW(_window), TRUE);
	gtk_window_set_position(GTK_WINDOW(_window), GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(_window), "destroy",
	                 G_CALLBACK(GTKDisplay::quit), nullptr);
	g_signal_connect(G_OBJECT(_window), "delete-event",
	                 G_CALLBACK(GTKDisplay::quit), nullptr);
	gtk_container_add(GTK_CONTAINER(_window), _tabs);
	gtk_widget_show_all(_window);
	gtk_main_iteration_do(FALSE);
	return true;
}

bool GTKDisplay::loadTabs(ModulePager &mp)
{
	auto cur = mp.getCurPage();
	auto head = cur;
	auto first = true;

	while (first || head.name != mp.getCurPage().name) {
		auto elem = std::pair<GtkWidget *, GtkWidget *>(
		    gtk_label_new(mp.getCurPage().name.c_str()),
		    gtk_fixed_new());
		for (auto e : mp.getCurPage().module)
			_panelArr[e] = elem.second;
		gtk_notebook_append_page(GTK_NOTEBOOK(_tabs), elem.second,
		                         elem.first);
		mp.inc();
		first = false;
	}
	_tabsLoaded = true;
	return true;
}

bool GTKDisplay::render(ModulePager &mp)
{
	auto head = mp.getCurPage();
	bool first = true;

	if (!_tabsLoaded)
		loadTabs(mp);
	while (true) {
		while (first || head.name != mp.getCurPage().name) {
			for (auto &e : mp.getCurPage().module)
				if (e->setup())
					e->render(*this);
			first = false;
			mp.inc();
		}
		gtk_widget_show_all(_window);
		gtk_main_iteration_do(FALSE);
	}
	return true;
}

bool GTKDisplay::clearRender()
{
	return true;
}

bool GTKDisplay::refreshRender()
{
	return true;
}

bool GTKDisplay::teardown()
{
	return true;
}

bool GTKDisplay::isIn(const AMonitorModule *module) const
{
	return _map.find(module) != _map.end();
}

bool GTKDisplay::addToDisplay(const AMonitorModule *module, GtkWidget *frame,
                              size_t x, size_t y)
{
	gtk_fixed_put(GTK_FIXED(_panelArr[module]), frame, x * 1280 / 100,
	              y * 720 / 100);
	_map[module] = true;
	return true;
}