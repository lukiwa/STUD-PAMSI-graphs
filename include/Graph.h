//
// Created by lukasz-lap on 04.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPH_H
#define STUD_PAMSI_GRAPHS_GRAPH_H

#include "List.h"
#include <memory>
#include <exception>
#include "Vertex.h"

/**
 * @brief graph class
 */
class Graph {
private:
    std::size_t number_of_edges;
    List<Vertex> vertices;
    List<Edge> adj_list;

public:
    Graph();

    //bool??
    bool insert_vertex(std::size_t id);

    //bool??
    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight);

    List<Edge> incident_edges(std::size_t id) const;


    bool remove_edge(const Edge &edge);

    bool remove_vertex(std::size_t id);

    friend std::ostream &operator<<(std::ostream &os, const Graph &obj);

};

#endif //STUD_PAMSI_GRAPHS_GRAPH_H
