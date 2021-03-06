/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** UserModule.hpp
*/

#ifndef CPP_RUSH3_USERMODULE_HPP
#define CPP_RUSH3_USERMODULE_HPP

#include <string>
#include <AMonitorModule.hpp>
#include <vector>

class UserModule : public AMonitorModule {
      public:
	UserModule(int x, int y, int w, int h);
	~UserModule();
	const std::string &getUsername() const;
	int getUid() const;
	const std::string &getDefaultShell() const;
	const std::string &getHomePath() const;
	const std::vector<std::string> &getGroupNames() const;
	const std::vector<gid_t> &getGroupGID() const;
	int getSid() const;
	const std::string &getHostName() const;
	virtual bool render(NcursesDisplay &display) const;
	virtual bool render(GTKDisplay &display) const;
	bool setup() override;
	void event(int c) override;
	bool isShow() const override;

private:
	void render_Ncurse(NcursesDisplay &display, Box const &b,
	Vec &v) const;
	std::string buildLabels(std::string &_str);
	std::string _username;
	int _uid;
	std::vector<gid_t> _groupGID;
	std::vector<std::string> _groupNames;
	int _sid;
	std::string _homePath;
	std::string _defaultShell;
	std::string _hostName;
	bool show;
	bool _loaded;
	GtkWidget *_frame;
	GtkWidget *_fixed;
	GtkWidget *_label;
};

#endif /* !CPP_RUSH3_USERMODULE_HPP */
