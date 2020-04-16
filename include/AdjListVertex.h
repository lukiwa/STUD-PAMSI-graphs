//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJLISTVERTEX_H
#define STUD_PAMSI_GRAPHS_ADJLISTVERTEX_H


#include <iostream>
#include <sstream>
#include "GraphEdge.h"
#include "List.h"


/**
 * @brief vertex of the graph
 */
struct AdjListVertex  {
    std::size_t data; //id (and data at the same time)
    List<GraphEdge> edges; //indices of edges at adj list


    ~AdjListVertex() = default;

    bool operator==(const AdjListVertex &v) {
        return v.data == this->data;
    }


    bool operator!=(const AdjListVertex &v) {
        return v.data != this->data;
    }

    /**
     * @brief Display AdjListVertex
     */
    friend std::ostream &operator<<(std::ostream &os, const AdjListVertex &obj) {
        os << obj.data;
        return os;
    }

};


#endif //STUD_PAMSI_GRAPHS_ADJLISTVERTEX_H
