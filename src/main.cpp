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
    std::cout << graph << std::endl;

    graph.insert_edge(0, 3, 1337);
    std::cout << graph << std::endl;

    graph.insert_edge(2, 69, 888);
    std::cout << graph << std::endl;

    std::cout << graph.incident_edges(69);

    return 0;

}
