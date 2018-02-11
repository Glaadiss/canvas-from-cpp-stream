cmake_minimum_required(VERSION 3.8)
project(lab4-1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Lab\ 4-1\ solution.cpp Playground.cpp Playground.h Rabbit.cpp Rabbit.h Dog.cpp Dog.h Cat.cpp Cat.h Breed.cpp Breed.h Animal.cpp Animal.h Console.cpp Console.h stdafx.cpp stdafx.h)

set(CURSES_NEED_NCURSES TRUE)

find_package(Curses REQUIRED)
include_directories( ${CURSES_INCLUDE_DIR} )

if(CURSES_HAVE_NCURSES_H)
    message([STATUS] "ncurses library found")
endif()

add_executable(backend ${SOURCE_FILES})

target_link_libraries( backend ${CURSES_LIBRARIES} )