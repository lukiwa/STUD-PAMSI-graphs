//
// Created by lukasz-lap on 04.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJLISTGRAPH_H
#define STUD_PAMSI_GRAPHS_ADJLISTGRAPH_H

#include "List.h"
#include <memory>
#include <exception>
#include "AdjListVertex.h"

/**
 * @brief graph class
 */
class AdjListGraph {
private:
    List<AdjListVertex> vertices;
    List<AdjListEdge> adj_list;

public:
    AdjListGraph();

    AdjListGraph(std::size_t number_of_vertices);

    bool insert_vertex(std::size_t id);

    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight);

    const List<AdjListEdge> incident_edges(std::size_t id) const;

    const List<AdjListVertex> &get_vertices() const;

    const List<AdjListEdge> &get_edges() const;

    List<std::size_t> end_vertices(const AdjListEdge &edge) const;

    std::size_t opposite(std::size_t vertex_id, const AdjListEdge &edge) const;

    bool are_adjacent(std::size_t v, std::size_t u) const;

    bool replace(const AdjListEdge &edge, unsigned new_weight);

    bool replace(std::size_t old_id, std::size_t new_id);


    friend std::ostream &operator<<(std::ostream &os, const AdjListGraph &obj);


    void remove_edge(const AdjListEdge &edge);


    void remove_vertex(std::size_t id);

};

#endif //STUD_PAMSI_GRAPHS_ADJLISTGRAPH_H
