#include <iostream>
#include <AdjListGraph.h>
#include <AdjMatrixGraph.h>
#include "List.h"
#include <chrono>
#include <algorithm>
#include "UtilityAlgorithms.h"
#include "AlgorithmsMST.h"


#define LOG(x) { std::cout << x << std::endl; }


int main() {

    AdjListGraph graph(6);
    graph.insert_edge(0, 1, 10);
    graph.insert_edge(1, 2, 20);
    graph.insert_edge(2, 3, 30);
    graph.insert_edge(3, 4, 40);
    graph.insert_edge(0, 4, 5);
    graph.insert_edge(4, 5, 15);


    auto res = utility::BellmanFord(graph, 0);
    for (int i = 0; i < graph.get_vertices().size(); ++i) {
        std::cout << i << "  " << res[i].first << "  " << res[i].second << std::endl;
    }
    delete [] res;


    return 0;

}
