cmake_minimum_required(VERSION 3.1)

project(zadacha2)

set(PROG_SRC Source.cpp CComplexVector.cpp CComplexVector0.cpp CComplexVector1.cpp Creator.cpp)
set(PROG_HDR AutoTest.hpp CComplexVector.h CComplexVector0.h CComplexVector1.h Creator.h)

configure_file(input.txt input.txt COPYONLY)

add_executable(${PROJECT_NAME} ${PROG_SRC} ${PROG_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -std=c++17")
