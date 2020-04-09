//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_VERTEX_H
#define STUD_PAMSI_GRAPHS_VERTEX_H


#include <iostream>
#include <sstream>
#include "Edge.h"
#include "List.h"

struct Vertex {
    std::size_t data;
    List<std::size_t> edges;

    ~Vertex() = default;

    bool operator==(const Vertex &v) {
        return v.data == this->data;
    }

    bool operator!=(const Vertex &v) {
        return v.data != this->data;
    }


    friend std::ostream &operator<<(std::ostream &os, const Vertex &obj) {
        os << obj.data;
        return os;
    }

};


#endif //STUD_PAMSI_GRAPHS_VERTEX_H
