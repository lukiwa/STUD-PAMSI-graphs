cmake_minimum_required(VERSION 3.15)
project(STUD_PAMSI_graphs)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )


include_directories(include ${Boost_INCLUDE_DIR})

add_executable(STUD_PAMSI_graphs src/main.cpp include/List.h include/ListNode.h include/ListNodeIterator.h src/AdjListGraph.cpp include/AdjListGraph.h include/GraphEdge.h include/GraphVertex.h src/AdjMatrixGraph.cpp include/AdjMatrixGraph.h include/Graph.h src/GraphEdge.cpp src/Graph.cpp src/GraphVertex.cpp include/UtilityAlgorithms.h src/GraphFileManager.cpp include/GraphFileManager.h src/RandomGraphGenerator.cpp include/RandomGraphGenerator.h src/GraphBuilder.cpp include/GraphBuilder.h src/UserInterface.cpp include/UserInterface.h src/ResultToFileSaver.cpp include/ResultToFileSaver.h)

target_link_libraries( STUD_PAMSI_graphs ${Boost_LIBRARIES} )
