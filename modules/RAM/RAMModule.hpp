/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** RAMModule.hpp
*/
#ifndef CPP_RUSH3_RAMMODULE_HPP_
#define CPP_RUSH3_RAMMODULE_HPP_

#include <AMonitorModule.hpp>

class RAMModule : public AMonitorModule {
      public:
	RAMModule(int x, int y, int w, int h);
	~RAMModule();
	bool render(NcursesDisplay &display) const;
	bool render(GTKDisplay &display) const;
	const std::map<std::string, std::string> &getMemInfos() const;
	void reloadData();
	size_t getUsedMemory() const;
	size_t getMemoryP() const;
	size_t getSwapP() const;
	bool setup();
	void event(int c);
	bool isShow() const override;

      private:
	size_t max;
	size_t available;
	size_t free;
	size_t swap;
	size_t swapfree;
	std::map<std::string, std::string> memInfos;
	bool show;
	GtkWidget *_frame;
	GtkWidget *_fixed;
	GtkWidget *_bar;
};

#endif // CPP_RUSH3_RAMMODULE_HPP_
