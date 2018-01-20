project(cpp_rush3)

cmake_minimum_required(VERSION 3.8)

set(sources
        modules/IMonitorModule.hpp
        display/IMonitorDisplay.hpp
        main.cpp
        modules/AMonitorModule.cpp
        modules/AMonitorModule.hpp
        modules/user/UserModule.cpp
        modules/user/UserModule.hpp
        modules/time/TimeModule.cpp
        modules/time/TimeModule.hpp
        modules/PC/PCModule.cpp
        modules/PC/PCModule.hpp
        display/ncurses/NcursesDisplay.cpp
        display/ncurses/NcursesDisplay.hpp)

add_executable(cpp_rush3 ${sources})

target_link_libraries(cpp_rush3 ncurses)

target_include_directories(cpp_rush3 PRIVATE modules display)