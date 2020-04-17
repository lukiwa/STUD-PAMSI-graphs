//
// Created by lukasz-lap on 14.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPHVERTEX_H
#define STUD_PAMSI_GRAPHS_GRAPHVERTEX_H

#include <iostream>
#include <sstream>


/**
 * @brief vertex of the graph
 */
struct GraphVertex {
    std::size_t id;
    int value;


    explicit GraphVertex(size_t id);

    GraphVertex(size_t id, int value);

    ~GraphVertex() = default;


    bool operator==(const GraphVertex &v);

    bool operator!=(const GraphVertex &v);

    friend std::ostream &operator<<(std::ostream &os, const GraphVertex &obj);


};

#endif //STUD_PAMSI_GRAPHS_GRAPHVERTEX_H
