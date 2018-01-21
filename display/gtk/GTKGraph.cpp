/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "GTKGraph.hpp"
#include <algorithm>
#include <iostream>

static Histo *h_g;

static void callback(GtkWidget *canvas, cairo_t *cr, gpointer data)
{
	GdkRGBA color;
	color.red = 0xFFFF;
	color.green = 0xFFFF;
	color.blue = 0xFFFF;
	color.alpha = 0xFFFF;
	(void)data;
	auto width = 0;
	auto height = 0;
	gtk_widget_get_size_request(canvas, &width, &height);
	size_t columns = (h_g->box.getWidth() * width) / 20;
	gdk_cairo_set_source_rgba(cr, &color);
	std::reverse(h_g->data.begin(), h_g->data.end());
	for (size_t i = 0; i < columns; i++) {
		auto colH =
		    h_g->data[i]
		        ? ((h_g->box.getHeigth() * height) / h_g->data[i])
		        : 0;
		cairo_rectangle(cr, (h_g->box.getX()) + i * 10, colH, 10,
		                (h_g->box.getHeigth() * height) - colH);
		cairo_fill(cr);
	}
	std::reverse(h_g->data.begin(), h_g->data.end());
}

void GTKGraph::drawHistoBox(GtkWidget const *canvas, Box const &b, Histo &h)
{
	(void)b;
	h_g = new Histo(h);
	g_signal_connect(G_OBJECT(canvas), "draw", G_CALLBACK(callback), 0);
	gtk_widget_queue_draw_area(GTK_WIDGET(canvas), 0, 0, b.getWidth(),
	                           b.getHeigth());
}