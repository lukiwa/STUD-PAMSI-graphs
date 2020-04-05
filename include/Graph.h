//
// Created by lukasz-lap on 04.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPH_H
#define STUD_PAMSI_GRAPHS_GRAPH_H

#include "List.h"
#include "Edge.h"


class Graph {
private:
    List<Edge> edges;
    List<Vertex> vertices;
    List<Vertex> *adj_list;
public:
    void add_vertex(int id);

    bool add_edge(Vertex from, Vertex to, unsigned weight = 0);

    Graph(std::size_t number_of_vertices);

};

#endif //STUD_PAMSI_GRAPHS_GRAPH_H
