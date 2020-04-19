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


    auto graph = std::make_shared<AdjListGraph>(9);
    graph->insert_edge(0, 1, 4);
    graph->insert_edge(0, 7, 8);
    graph->insert_edge(1, 2, 8);
    graph->insert_edge(1, 7, 11);
    graph->insert_edge(2, 3, 7);
    graph->insert_edge(2, 8, 2);
    graph->insert_edge(2, 5, 4);
    graph->insert_edge(3, 4, 9);
    graph->insert_edge(3, 5, 14);
    graph->insert_edge(4, 5, 10);
    graph->insert_edge(5, 6, 2);
    graph->insert_edge(6, 7, 1);
    graph->insert_edge(6, 8, 6);
    graph->insert_edge(7, 8, 7);


    LOG(mst::KruskalMST(graph))


/*
    List<int> list;
    for (int i = 50; i >= 0; --i) {
        list.push_back(i);
    }
    auto start = std::chrono::steady_clock::now();
    utility::sort_list(list);
    auto end = std::chrono::steady_clock::now();


    LOG(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count())
    LOG(list)
*/
    return 0;

}
