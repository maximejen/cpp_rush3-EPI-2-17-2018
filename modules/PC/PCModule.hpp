/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** PCModule.hpp
*/

#ifndef CPP_RUSH3_PCMODULE_HPP_
	#define CPP_RUSH3_PCMODULE_HPP_

	#include <AMonitorModule.hpp>
	#include "AMonitorModule.hpp"
	#include <string>
	#include <map>

class PCModule : public AMonitorModule {
public:
	explicit PCModule(int x, int y, int w, int h);
	~PCModule();
	const std::map<std::string, std::string> &getOsInfos() const;
	const std::string &getKernelVersion() const;
	const std::string &getPCModel() const;
	virtual bool render(NcursesDisplay &display) const;
	virtual bool render(GTKDisplay &display) const;
	bool setup();
	void reloadModule();
private:
	std::string _type;
	const std::string osReleaseFile;
	const std::string kernelOSReleaseFile;
	const std::string kernelOSTypeFile;
	const std::string pcModelFile;
	std::map<std::string, std::string> osInfos;
	std::string kernelVersion;
	std::string pcModel;
};

#endif /* !CPP_RUSH3_PCMODULE_HPP_ */
