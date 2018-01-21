/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** PCModule.hpp
*/

#ifndef CPP_RUSH3_PCMODULE_HPP_
#define CPP_RUSH3_PCMODULE_HPP_

#include "AMonitorModule.hpp"
#include <AMonitorModule.hpp>
#include <map>
#include <string>

class PCModule : public AMonitorModule {
      public:
	explicit PCModule(int x, int y, int w, int h);
	~PCModule();
	bool render(NcursesDisplay &display) const;
	bool render(GTKDisplay &display) const;
	const std::map<std::string, std::string> &getOsInfos() const;
	const std::string &getKernelVersion() const;
	const std::string &getPCModel() const;
	bool setup();
	void reloadModule();
	bool isShow() const override;
	void event(int c) override;

private:
	std::string prepareVersion(std::string &str) const;
	std::string _type;
	const std::string osReleaseFile;
	const std::string kernelOSReleaseFile;
	const std::string kernelOSTypeFile;
	const std::string pcModelFile;
	std::map<std::string, std::string> osInfos;
	std::string kernelVersion;
	std::string pcModel;
	bool show;
	GtkWidget *_frame;
	GtkWidget *_fixed;
	GtkWidget *_label;
};

#endif /* !CPP_RUSH3_PCMODULE_HPP_ */
