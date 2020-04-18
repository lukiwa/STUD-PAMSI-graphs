#include <iostream>
#include <AdjListGraph.h>
#include <AdjMatrixGraph.h>
#include "List.h"


#define LOG(x) { std::cout << x << std::endl }

int main() {


    AdjMatrixGraph graph(5);
    graph.insert_edge(0, 3, 1337);
    graph.insert_edge(0, 1, 420);

    graph.insert_vertex(14);
    graph.remove_vertex(3);
    LOG(graph);


    return 0;

}
