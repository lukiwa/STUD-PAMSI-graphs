#include <iostream>
#include "List.h"
#include "NodeIterator.h"
#include "AdjListGraph.h"


int main() {


    AdjListGraph graph(4);


    graph.insert_edge(0, 1, 420);
    graph.insert_edge(0, 3, 1337);


    std::cout << graph << std::endl;


    return 0;

}
