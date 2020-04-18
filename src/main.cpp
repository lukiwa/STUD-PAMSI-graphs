#include <iostream>
#include <AdjListGraph.h>
#include <AdjMatrixGraph.h>
#include "List.h"
#include <chrono>


#define LOG(x) { std::cout << x << std::endl; }


int main() {


    AdjListGraph graph(5);
    graph.insert_edge(0, 3, 10);
    graph.insert_edge(0, 1, 8);
    graph.insert_edge(0, 2, 7);
    graph.insert_edge(3, 4, 6);
    LOG(graph.get_edges())


/*

    List<int> list;


    for (int i = 20; i >= 0; --i) {
        list.push_back(i);
    }
    list.sort(list.begin());

    LOG(list)

*/
    return 0;

}
