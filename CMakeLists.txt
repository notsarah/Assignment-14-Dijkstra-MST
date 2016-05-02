cmake_minimum_required(VERSION 3.3)
project(Assign_14___Dijkstra___MST)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.h Edge.h Vertex.h OutputHeading.cpp Header.h)
add_executable(Assign_14___Dijkstra___MST ${SOURCE_FILES})