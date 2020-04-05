cmake_minimum_required(VERSION 3.15)
project(STUD_PAMSI_graphs)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(STUD_PAMSI_graphs src/main.cpp include/List.h include/Node.h include/NodeIterator.h src/Graph.cpp include/Graph.h include/Vertex.h include/Edge.h)