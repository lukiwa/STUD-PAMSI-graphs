#include <iostream>
#include "List.h"
#include "ListNodeIterator.h"
#include "AdjListGraph.h"
#include "AdjMatrixGraph.h"

int main() {


    AdjMatrixGraph graph(4);

    graph.insert_edge(0, 1, 420);
    std::cout << graph << std::endl;


    return 0;

}
