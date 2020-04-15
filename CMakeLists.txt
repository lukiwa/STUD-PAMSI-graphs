cmake_minimum_required(VERSION 3.15)
project(STUD_PAMSI_graphs)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(STUD_PAMSI_graphs src/main.cpp include/List.h include/ListNode.h include/ListNodeIterator.h src/AdjListGraph.cpp include/AdjListGraph.h include/AdjListVertex.h include/GraphEdge.h include/AdjMatrixVertex.h src/AdjMatrixGraph.cpp include/AdjMatrixGraph.h)