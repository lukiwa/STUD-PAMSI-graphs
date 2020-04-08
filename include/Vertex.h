//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_VERTEX_H
#define STUD_PAMSI_GRAPHS_VERTEX_H

#include "List.h"
#include "Edge.h"
#include <iostream>
#include <sstream>

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

    //TODO FIX
    void add_edge(const Edge &edge) {
        edges.push_back(edge);
    }


    friend std::ostream &operator<<(std::ostream &os, const Vertex &obj) {
        os << obj.id << " ";
        os << obj.edges << " ";

        return os;
    }

};


#endif //STUD_PAMSI_GRAPHS_VERTEX_H
