//
// Created by lukasz-lap on 14.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
#define STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H

#include "AdjMatrixEdge.h"
#include "List.h"

class AdjMatrixGraph {
private:
    List<AdjMatrixVertex> veritces;
    int **adj_matrix;
public:
    AdjMatrixGraph(std::size_t number_of_vertices);


};


#endif //STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
