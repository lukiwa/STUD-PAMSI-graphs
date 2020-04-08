//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_EDGE_H
#define STUD_PAMSI_GRAPHS_EDGE_H

#include "Vertex.h"
#include <iostream>
#include <sstream>

class Vertex;

struct Edge {
    Vertex from;
    Vertex to;
    unsigned weight;

    friend std::ostream &operator<<(std::ostream &os, const Edge &obj) {
        std::ostringstream buff;

        buff << "{ " <<
             obj.from.id << " " <<
             obj.to.id << " " <<
             obj.weight << " }";

        os << buff.str();

        return os;
    }
};

#endif //STUD_PAMSI_GRAPHS_EDGE_H

