cmake_minimum_required(VERSION 3.20.2)
project(CloudPOO_eng_ini)

set(CMAKE_CXX_STANDARD 20)

add_executable(cloudpoo main.cpp Generator.cpp Generator.h Device.cpp Device.h DataCenter.cpp DataCenter.h)
