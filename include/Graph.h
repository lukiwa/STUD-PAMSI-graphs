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

    bool insert_vertex(std::size_t id);

    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight);

    List<Edge> incident_edges(std::size_t id) const;

    const List<Vertex> &get_vertices() const;

    const List<Edge> &get_edges() const;

    List<std::size_t> end_vertices(const Edge &edge) const;

    std::size_t opposite(std::size_t vertex_id, const Edge &edge) const;

    bool are_adjacent(std::size_t v, std::size_t u) const;

    bool replace(const Edge &edge, unsigned new_weight);

    bool replace(std::size_t old_id, std::size_t new_id);


    friend std::ostream &operator<<(std::ostream &os, const Graph &obj);

    //not working
    bool remove_edge(const Edge &edge);

    //not working
    bool remove_vertex(std::size_t id);

};

#endif //STUD_PAMSI_GRAPHS_GRAPH_H
