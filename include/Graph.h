//
// Created by lukasz-lap on 04.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPH_H
#define STUD_PAMSI_GRAPHS_GRAPH_H

#include "List.h"
#include <memory>
#include <exception>
#include "Vertex.h"

class Graph {
public:
    std::size_t number_of_edges;
    List<Vertex> vertices;
    List<Edge> adj_list;

public:
    Graph();

    bool insert_vertex(std::size_t id);

    bool insert_edge(std::size_t from, std::size_t to, unsigned weight);

    bool remove_edge(const Edge &edge);

    bool remove_vertex(std::size_t id);

    friend std::ostream &operator<<(std::ostream &os, const Graph &obj);

};

#endif //STUD_PAMSI_GRAPHS_GRAPH_H
