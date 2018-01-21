/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#ifndef GTKGRAPH_HPP_
#define GTKGRAPH_HPP_

#include "AMonitorModule.hpp"
#include "ncurses/tool/NcursesTool.hpp"

class GTKGraph {
      public:
	static void drawHistoBox(GtkWidget const *canvas, Box const &b,
	                        Histo &h);

      protected:
      private:
};

#endif /* !GTKGRAPH_HPP_ */
