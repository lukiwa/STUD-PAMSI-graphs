//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_VERTEX_H
#define STUD_PAMSI_GRAPHS_VERTEX_H

#include "List.h"
#include "Edge.h"

class Edge;

struct Vertex {
    int id;
    List<Edge> edges;

    ~Vertex() = default;

    bool operator==(Vertex v) {
        return v.id == this->id;
    }

    bool operator!=(Vertex v) {
        return v.id != this->id;
    }
};

#endif //STUD_PAMSI_GRAPHS_VERTEX_H
