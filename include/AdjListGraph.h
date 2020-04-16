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
    List<GraphEdge> adj_list;

public:
    AdjListGraph() = default;

    ~AdjListGraph() = default;

    AdjListGraph(std::size_t number_of_vertices);

    bool insert_vertex(std::size_t id);

    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight);

    const List<GraphEdge> incident_edges(std::size_t id) const;

    List<AdjListVertex> get_vertices() const;

    List<GraphEdge> get_edges() const;

    List<std::size_t> end_vertices(const GraphEdge &edge) const;

    std::size_t opposite(std::size_t vertex_id, const GraphEdge &edge) const;

    bool are_adjacent(std::size_t v, std::size_t u) const;

    bool replace(const GraphEdge &edge, unsigned new_weight);

    bool replace(std::size_t old_id, std::size_t new_id);


    friend std::ostream &operator<<(std::ostream &os, const AdjListGraph &obj);


    void remove_edge(const GraphEdge &edge);


    void remove_vertex(std::size_t id);

};

#endif //STUD_PAMSI_GRAPHS_ADJLISTGRAPH_H
