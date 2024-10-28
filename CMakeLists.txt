cmake_minimum_required(VERSION 3.29)
project(15_puzzle_game)

set(CMAKE_CXX_STANDARD 26)
set(SRC
        src/main.cpp
        src/models/game.cpp)

include_directories(
        include
        include/models)

add_executable(15_puzzle_game ${SRC})
