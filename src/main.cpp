#include <iostream>
#include <AdjListGraph.h>
#include <AdjMatrixGraph.h>
#include "List.h"
#include <chrono>
#include <algorithm>
#include "UtilityAlgorithms.h"
#include <random>
#include "RandomGraphGenerator.h"


#define LOG(x) { std::cout << x << std::endl; }


int main() {
    srand(time(NULL));
/*
    AdjListGraph graph;
    for (int j = 0; j < 6; ++j) {
        graph.insert_vertex(j);
    }
    graph.insert_edge(0, 1, 10);
    graph.insert_edge(1, 2, 20);
    graph.insert_edge(2, 3, 30);
    graph.insert_edge(3, 4, 40);
    graph.insert_edge(0, 4, 5);
    graph.insert_edge(4, 5, 15);

    LOG(graph)
    auto res = utility::BellmanFord(graph, 1);
    for (std::size_t i = 0; i < graph.get_vertices().size(); ++i) {
        std::cout << i << "  " << res[i].first << "  " << res[i].second << std::endl;
    }
*/
    AdjMatrixGraph graph(10);
    RandomGraphGenerator rg(graph);
    rg.Generate();
    LOG(graph)
    auto res = utility::BellmanFord(graph, 0);
    for (std::size_t i = 0; i < graph.get_vertices().size(); ++i) {
        std::cout << i << "  " << res[i].first << "  " << res[i].second << std::endl;
    }

    return 0;

}
