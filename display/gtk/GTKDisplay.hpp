/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#ifndef GTKDISPLAY_HPP_
#define GTKDISPLAY_HPP_

#include "AMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <gtk/gtk.h>
#include <map>
#include <utility>
#include <vector>

class AMonitorModule;
class IMonitorModule;

class GTKDisplay : public IMonitorDisplay {
      public:
	GTKDisplay();
	~GTKDisplay();
	bool setup();
	bool render(ModulePager &mp);
	bool refreshRender();
	bool clearRender();
	bool teardown();
	bool isIn(const AMonitorModule *) const;
	bool addToDisplay(const AMonitorModule *, GtkWidget *, size_t, size_t);
	bool loadTabs(ModulePager &mp);

      protected:
      private:
	GtkWidget *_window;
	std::map<std::string, std::pair<GtkWidget *, GtkWidget *>> _fixed;
	std::map<const AMonitorModule *, GtkWidget *> _panelArr;
	GtkWidget *_tabs;
	bool _tabsLoaded;
	std::map<const AMonitorModule *, bool> _map;
	static void quit();
};

#endif /* !GTKDISPLAY_HPP_ */
