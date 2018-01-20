/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#ifndef GTKDISPLAY_HPP_
#define GTKDISPLAY_HPP_

#include <vector>
#include <utility>
#include <gtk/gtk.h>
#include "IMonitorDisplay.hpp"
#include "AMonitorModule.hpp"
#include "GTKModule.hpp"

class AMonitorModule;
class IMonitorModule;

class GTKDisplay : public IMonitorDisplay {
      public:
        GTKDisplay();
        ~GTKDisplay();
	bool setup();
	bool render();
	bool refreshRender();
	bool clearRender();
	bool teardown();
        GtkWidget *_fixed;

      protected:
      private:
        GtkWidget *_window;
	std::vector<AMonitorModule *> _modules;
};

#endif /* !GTKDISPLAY_HPP_ */
