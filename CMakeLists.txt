cmake_minimum_required(VERSION 3.17)
project(starWarsHomework)

set(CMAKE_CXX_STANDARD 14)

add_executable(starWarsHomework main.cpp Planet.h Planet.cpp Stormtrooper.h Stormtrooper.cpp Jedi.h Jedi.cpp BattleShip.h cmake-build-debug/BatleShip.cpp)