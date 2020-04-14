#include <iostream>
#include "List.h"
#include "NodeIterator.h"
#include "Graph.h"


int main() {


    Graph graph{};
    graph.insert_vertex(0);
    graph.insert_vertex(1);
    graph.insert_vertex(2);
    graph.insert_vertex(3);
    graph.insert_vertex(69);


    graph.insert_edge(0, 1, 420);
    graph.insert_edge(0, 3, 1337);
    graph.insert_edge(2, 69, 94);
    std::cout << graph << std::endl;

    graph.replace(69, 9);

    std::cout << graph << std::endl;

    return 0;

}
