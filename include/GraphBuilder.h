//
// Created by lukasz-lap on 25.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPHBUILDER_H
#define STUD_PAMSI_GRAPHS_GRAPHBUILDER_H

#include "AdjListGraph.h"
#include "AdjMatrixGraph.h"
#include "RandomGraphGenerator.h"

enum GraphType {
    LIST, MATRIX
};

class GraphBuilder {
    double density;
    std::size_t number_of_vertices;
    std::size_t number_of_edges;

    std::unique_ptr<Graph> graph;
    std::unique_ptr<RandomGraphGenerator> generator;
    GraphType type;
public:
    GraphBuilder &SetType(GraphType type);

    GraphBuilder &SetSize(std::size_t size);

    GraphBuilder &SetDensity(double density);

    std::unique_ptr<Graph> Build();

};


#endif //STUD_PAMSI_GRAPHS_GRAPHBUILDER_H
