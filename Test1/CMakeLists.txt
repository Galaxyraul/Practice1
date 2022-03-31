cmake_minimum_required(VERSION 3.21)
project(Test1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test1 main.cpp ControlTower.cpp ControlTower.h Drone.cpp Drone.h Parcel.cpp Parcel.h)
