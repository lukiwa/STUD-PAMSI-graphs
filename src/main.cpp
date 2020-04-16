#include <iostream>
#include "List.h"
#include "AdjMatrixGraph.h"

int main() {


    AdjMatrixGraph graph(3);


    graph.insert_vertex(14);
    graph.insert_vertex(0);
    graph.insert_vertex(0);
    graph.insert_edge(0, 1, 420);
    graph.insert_edge(0, 3, 1337);


    graph.remove_vertex(14);
    std::cout << graph << std::endl;


    return 0;

}
