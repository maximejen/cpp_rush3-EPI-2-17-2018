project(cpp_rush3)

cmake_minimum_required(VERSION 3.8)

set(sources
        display/gtk/GTKDisplay.cpp
        display/gtk/GTKDisplay.hpp
        display/gtk/GTKGraph.cpp
        display/gtk/GTKGraph.hpp
        display/IMonitorDisplay.hpp
        display/ModulePager.cpp
        display/ModulePager.hpp
        display/ncurses/NcursesDisplay.cpp
        display/ncurses/NcursesDisplay.hpp
        display/ncurses/NcursesDisplay.hpp
        display/ncurses/tool/NcursesTool.cpp
        display/ncurses/tool/NcursesTool.hpp
        main.cpp
        modules/AMonitorModule.cpp
        modules/AMonitorModule.hpp
        modules/CPU/CPUModule.cpp
        modules/CPU/CPUModule.hpp
        modules/IMonitorModule.hpp
        modules/Network/NetworkModule.cpp
        modules/Network/NetworkModule.hpp
        modules/PC/PCModule.cpp
        modules/PC/PCModule.hpp
        modules/RAM/RAMModule.cpp
        modules/RAM/RAMModule.hpp
        modules/time/TimeModule.cpp
        modules/time/TimeModule.hpp
        modules/user/UserModule.cpp
        modules/user/UserModule.hpp
        Parser.cpp Parser.hpp)

add_executable(cpp_rush3 ${sources})

target_link_libraries(cpp_rush3 ncurses gtk-3 gobject-2.0 gdk-3 cairo)

target_include_directories(cpp_rush3 PRIVATE modules display /usr/include/gtk-3.0 /usr/include/glib-2.0 /usr/lib/glib-2.0/include/ /usr/include/pango-1.0 /usr/include/cairo /usr/include/gdk-pixbuf-2.0 /usr/include/atk-1.0 /usr/include/glib-2.0 /usr/lib64/glib-2.0/include /usr/lib/x86_64-linux-gnu/glib-2.0/include/)

target_compile_options(cpp_rush3 PUBLIC -W -Wall -Wextra -Werror)
