/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "GTKDisplay.hpp"
#include "PC/PCModule.hpp"
#include "time/TimeModule.hpp"

GTKDisplay::GTKDisplay()
{
	_modules.push_back(new TimeModule(20, 20, 300, 50));
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
	gtk_window_set_resizable(GTK_WINDOW(_window), TRUE);
	gtk_window_set_position(GTK_WINDOW(_window), GTK_WIN_POS_CENTER);

	_fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(_window), _fixed);
	g_signal_connect(G_OBJECT(_window), "destroy",
	                 G_CALLBACK(GTKDisplay::quit), nullptr);
	gtk_widget_show_all(_window);
	gtk_main_iteration_do(FALSE);
	return true;
}

bool GTKDisplay::render(ModulePager &mp)
{
	while (true) {
		for (auto &e : mp.getCurPage().module)
			if (e->setup())
				e->render(*this);
		gtk_widget_show_all(_window);
		gtk_main_iteration_do(FALSE);
	}
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
	gtk_fixed_put(GTK_FIXED(_fixed), frame, x, y);
	_map[module] = true;
	return true;
}