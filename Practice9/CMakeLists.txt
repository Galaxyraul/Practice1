cmake_minimum_required(VERSION 3.19)
project(prueba)

set(CMAKE_CXX_STANDARD 20)

FILE(GLOB SOURCE_FILES *.cpp)

ADD_EXECUTABLE(a.exe ${SOURCE_FILES} Sword.cpp Sword.h Steak.cpp Steak.h Block.cpp Block.h ItemApilable.cpp ItemApilable.h EmptyContainer.h ItemArrojable.h ItemApilableArrojable.cpp ItemApilableArrojable.h ItemAgotado.h SnowBall.cpp SnowBall.h)
