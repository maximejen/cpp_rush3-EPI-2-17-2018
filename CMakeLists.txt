project(cpp_rush3)

cmake_minimum_required(VERSION 3.9)

set(sources modules/IMonitorModule.hpp diplay/IMonitorDisplay.hpp main.cpp modules/AMonitorModule.cpp modules/AMonitorModule.hpp)

add_executable(cpp_rush3 ${sources})

target_include_directories(cpp_rush3 PRIVATE modules diplay)