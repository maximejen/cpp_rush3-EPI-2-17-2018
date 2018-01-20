project(cpp_rush3)

cmake_minimum_required(VERSION 3.8)

set(sources
        modules/IMonitorModule.hpp
        diplay/IMonitorDisplay.hpp
        main.cpp
        modules/AMonitorModule.cpp
        modules/AMonitorModule.hpp
        modules/user/UserModule.cpp
        modules/user/UserModule.hpp
        modules/time/TimeModule.cpp
        modules/time/TimeModule.hpp
        modules/PC/PCModule.cpp
        modules/PC/PCModule.hpp)

add_executable(cpp_rush3 ${sources})

target_include_directories(cpp_rush3 PRIVATE modules diplay)