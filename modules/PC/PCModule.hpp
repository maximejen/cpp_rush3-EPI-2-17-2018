/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** PCModule.hpp
*/

#ifndef CPP_RUSH3_PCMODULE_HPP
#define CPP_RUSH3_PCMODULE_HPP

#include "gtk/GTKDisplay.hpp"
#include "AMonitorModule.hpp"
#include <string>

class PCModule : public AMonitorModule {
      public:
        PCModule(const std::string &_type);
        ~PCModule();
        const std::string &getType() const;
        bool render(IMonitorDisplay &display) const;
        bool render(GTKDisplay &display) const;
        void clear(IMonitorDisplay &display) const;
        bool getInfos();

      protected:
      private:
        std::string _type;
};

#endif /* !CPP_RUSH3_PCMODULE_HPP */
