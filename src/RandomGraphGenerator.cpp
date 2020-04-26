//
// Created by lukasz-lap on 22.04.2020.
//

#include "RandomGraphGenerator.h"

/**
 * @brief Generate graph with parameters set by builder
 */
void RandomGraphGenerator::Generate() {
    std::size_t created_edges = 0;
    GraphEdge tmp;
    List<GraphEdge> spanning;


    //start with 2 vertices connected
    graph.insert_edge(0, 1, random() % max_weight + 1);
    ++created_edges;

    //generate "spanning tree"
    for (std::size_t i = 2; i < number_of_vertices; ++i) {
        tmp.from_id = random() % i;
        tmp.to_id = i;
        tmp.weight = random() % max_weight + 1;
        graph.insert_edge(tmp.from_id, tmp.to_id, tmp.weight);
        ++created_edges;
    }


    while (created_edges < number_of_edges) {
        tmp.from_id = random() % number_of_vertices;
        tmp.to_id = random() % number_of_vertices;
        tmp.weight = random() % max_weight + 1;

        //avoid loops
        if (tmp.from_id == tmp.to_id) {
            continue;
        }

        //avoid duplicates
        if (!graph.insert_edge(tmp.from_id, tmp.to_id, tmp.weight)) {
            continue;
        }
        ++created_edges;
    }
}

/**
 * @brief Constructs new generator class
 * @param graph graph to be filled with edges
 */
RandomGraphGenerator::RandomGraphGenerator(Graph &graph) :
        graph(graph) {
}




