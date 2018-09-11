cmake_minimum_required(VERSION 2.6)
project(learncmake)

add_executable(learncmake main.cpp)

install(TARGETS learncmake RUNTIME DESTINATION bin)
