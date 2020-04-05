//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_EDGE_H
#define STUD_PAMSI_GRAPHS_EDGE_H

#include "Vertex.h"


struct Edge {
    Vertex from;
    Vertex to;
    unsigned weight;
};

#endif //STUD_PAMSI_GRAPHS_EDGE_H

