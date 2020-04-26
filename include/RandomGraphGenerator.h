//
// Created by lukasz-lap on 22.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_RANDOMGRAPHGENERATOR_H
#define STUD_PAMSI_GRAPHS_RANDOMGRAPHGENERATOR_H


#include <iostream>
#include "Graph.h"
#include "AdjMatrixGraph.h"
#include "AdjListGraph.h"

class GraphBuilder;

class RandomGraphGenerator {
private:

    RandomGraphGenerator() = default;


    friend class GraphBuilder;

    Graph& graph;

    double density;
    std::size_t max_weight = INT8_MAX;
    std::size_t number_of_vertices;
    std::size_t number_of_edges;
public:

    explicit RandomGraphGenerator(Graph& graph);

    void Generate();

};


#endif //STUD_PAMSI_GRAPHS_RANDOMGRAPHGENERATOR_H
