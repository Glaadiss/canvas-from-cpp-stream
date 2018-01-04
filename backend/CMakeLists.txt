cmake_minimum_required(VERSION 3.6)
project(backend)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp json.hh)
add_executable(backend ${SOURCE_FILES})


