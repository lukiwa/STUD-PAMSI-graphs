#include <iostream>
#include <AdjListGraph.h>
#include <AdjMatrixGraph.h>
#include "List.h"


int main() {


    AdjListGraph graph(5);
    graph.insert_edge(0, 3, 1337);
    graph.insert_edge(0, 1, 420);

    graph.insert_vertex(14);
    std::cout << graph.are_adjacent(0, 0) << std::endl;


    return 0;

}
