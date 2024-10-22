cmake_minimum_required(VERSION 3.29)
project(15_puzzle_game)

set(CMAKE_CXX_STANDARD 26)

include_directories(
        include
        include/models)

add_executable(15_puzzle_game src/main.cpp
        src/models/game.cpp
        include/models/game.h
        include/models/user.h
        src/models/user.cpp)
