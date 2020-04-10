//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_VERTEX_H
#define STUD_PAMSI_GRAPHS_VERTEX_H


#include <iostream>
#include <sstream>
#include "Edge.h"
#include "List.h"

/**
 * @brief vertex of the graph
 */
struct Vertex {
    std::size_t data; //id
    List<std::size_t> edges; //indices of edges at adj list


    ~Vertex() = default;

    bool operator==(const Vertex &v) {
        return v.data == this->data;
    }


    bool operator!=(const Vertex &v) {
        return v.data != this->data;
    }

    /**
     * @brief Display Vertex
     */
    friend std::ostream &operator<<(std::ostream &os, const Vertex &obj) {
        os << obj.data;
        return os;
    }

};


#endif //STUD_PAMSI_GRAPHS_VERTEX_H
