cmake_minimum_required(VERSION 3.10)
project(minesweeperbot)
set(SOURCES
    src/main.cpp
    src/filereader.cpp
    src/board.cpp
    src/parseboard.cpp)
add_executable(build ${SOURCES})

