//
// Created by lukasz-lap on 22.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_RANDOMGRAPHGENERATOR_H
#define STUD_PAMSI_GRAPHS_RANDOMGRAPHGENERATOR_H


#include <iostream>
#include "Graph.h"
#include "AdjMatrixGraph.h"
#include "AdjListGraph.h"


class RandomGraphGenerator {
private:
    Graph &graph;
    double density = 1;
    std::size_t max_weight = INT8_MAX; //in order to fit as sum of max 1000 in type int32
    std::size_t number_of_vertices;
    std::size_t number_of_edges;
public:

    RandomGraphGenerator(Graph &graph) : graph(graph) {
        number_of_vertices = graph.get_vertices().size();
        number_of_edges = static_cast<std::size_t >(
                (density * number_of_vertices *
                 (number_of_vertices - 1)) / 2);
    }

    void Generate() {

        std::size_t created_edges = 0;
        GraphEdge tmp;


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

            //avoid doubling edges
            if (graph.get_edges().is_present(tmp)) {
                continue;
            }
            graph.insert_edge(tmp.from_id, tmp.to_id, tmp.weight);
            ++created_edges;

        }

    }

};


#endif //STUD_PAMSI_GRAPHS_RANDOMGRAPHGENERATOR_H
