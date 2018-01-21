project(cpp_rush3)

cmake_minimum_required(VERSION 3.8)

set(sources
        modules/IMonitorModule.hpp
        display/IMonitorDisplay.hpp
        main.cpp
        modules/CPU/CPUModule.cpp
        modules/CPU/CPUModule.hpp
        modules/AMonitorModule.cpp
        modules/AMonitorModule.hpp
        modules/user/UserModule.cpp
        modules/user/UserModule.hpp
        modules/time/TimeModule.cpp
        modules/time/TimeModule.hpp
        modules/PC/PCModule.cpp
        modules/PC/PCModule.hpp
        display/ncurses/NcursesDisplay.cpp
        display/ncurses/NcursesDisplay.hpp
        display/ncurses/tool/NcursesTool.cpp
        display/ncurses/tool/NcursesTool.hpp
        display/ncurses/NcursesDisplay.hpp
        display/gtk/GTKDisplay.cpp
        display/gtk/GTKDisplay.hpp
        Parser.cpp Parser.hpp modules/RAM/RAMModule.cpp modules/RAM/RAMModule.hpp)

add_executable(cpp_rush3 ${sources})

target_link_libraries(cpp_rush3 ncurses gtk-3 gobject-2.0 glib-2.0)

target_include_directories(cpp_rush3 PRIVATE modules display /usr/include/gtk-3.0 /usr/include/glib-2.0 /usr/lib/glib-2.0/include/ /usr/include/pango-1.0 /usr/include/cairo /usr/include/gdk-pixbuf-2.0 /usr/include/atk-1.0 /usr/include/glib-2.0 /usr/lib64/glib-2.0/include /usr/lib/x86_64-linux-gnu/glib-2.0/include/)

target_compile_options(cpp_rush3 PUBLIC -W -Wall -Wextra -Werror)
