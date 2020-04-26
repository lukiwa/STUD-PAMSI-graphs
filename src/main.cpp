#include <iostream>
#include <AdjListGraph.h>
#include <AdjMatrixGraph.h>
#include "List.h"
#include <chrono>
#include <algorithm>
#include <random>
#include "RandomGraphGenerator.h"
#include "GraphBuilder.h"
#include <boost/program_options.hpp>
#include <string>
#include <UserInterface.h>
//#include "UtilityAlgorithms.h"


#define LOG(x) { std::cout << std::boolalpha<< x << std::endl; }


int main(int argc, char **argv) {

    srand(time(NULL));
    UserInterface ui;
    ui.Begin(argc, argv);


/*
    std::unique_ptr<Graph> graph = std::make_unique<AdjMatrixGraph>(10);

    graph->insert_edge(0, 1, 20);
    graph->insert_edge(0, 2, 50);
    graph->insert_edge(0, 3, 37);
    graph->insert_edge(1, 3, 84);
    graph->insert_edge(1, 4, 40);
    graph->insert_edge(1, 9, 101);
    graph->insert_edge(2, 5, 105);
    graph->insert_edge(2, 6, 126);
    graph->insert_edge(6, 7, 95);
    graph->insert_edge(5, 6, 126);
    graph->insert_edge(4, 8, 101);
    LOG(graph->are_adjacent(8,4))

    auto res = utility::BellmanFord(*graph, 0);

    for (std::size_t i = 0; i < graph->get_vertices().size(); ++i) {
        std::cout << i << "  " << res[i].first << "  " << res[i].second << std::endl;
    }
*/


/*

    GraphBuilder builder;
    auto start = std::chrono::steady_clock::now();
    auto graph = builder.SetType(LIST).
            SetSize(1000).
            SetDensity(1).Build();
    auto res = utility::BellmanFord(*graph, 0);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Elapsed time in nanoseconds : "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;
    /*
     for (std::size_t i = 0; i < graph->get_vertices().size(); ++i) {
         std::cout << i << "  " << res[i].first << "  " << res[i].second << std::endl;
     }
 */
    return 0;

}
