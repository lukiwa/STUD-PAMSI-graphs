//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPHEDGE_H
#define STUD_PAMSI_GRAPHS_GRAPHEDGE_H

#include <iostream>
#include <sstream>


/**
 * @brief GraphEdge of the graph
 */
struct GraphEdge {
    std::size_t from_id;
    std::size_t to_id;
    unsigned weight;

    GraphEdge();

    GraphEdge(size_t fromId, size_t toId, unsigned int weight);

    ~GraphEdge() = default;


    bool operator==(const GraphEdge &e);

    bool operator!=(const GraphEdge &e);

    bool operator<(const GraphEdge &e);

    friend std::ostream &operator<<(std::ostream &os, const GraphEdge &obj);


};

#endif //STUD_PAMSI_GRAPHS_GRAPHEDGE_H

