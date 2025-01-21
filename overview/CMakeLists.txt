cmake_minimum_required(VERSION 3.31)

project(overview LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(overview main.c
    myutils.h myutils.c
    myheaderfile.h source.c
)

include(GNUInstallDirs)
install(TARGETS overview
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
