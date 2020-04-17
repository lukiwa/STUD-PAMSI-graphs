#include <iostream>
#include <AdjListGraph.h>
#include "List.h"


int main() {


    AdjListGraph graph(16);
    graph.insert_edge(0, 3, 1337);
    graph.insert_edge(0, 1, 420);


    std::cout << graph << std::endl;


    return 0;

}
