#include <iostream>
#include "List.h"
#include "NodeIterator.h"
#include "Graph.h"


int main() {

    Graph graph(10);
    graph.add_single_edge(Vertex{0}, Vertex{2}, 10);
    graph.add_single_edge(Vertex{0}, Vertex{3}, 17);

    std::cout << graph.vertices.front();
    // std::cout << graph.edges;
    return 0;

}
