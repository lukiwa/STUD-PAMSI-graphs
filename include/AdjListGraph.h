//
// Created by lukasz-lap on 04.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJLISTGRAPH_H
#define STUD_PAMSI_GRAPHS_ADJLISTGRAPH_H

#include "List.h"
#include <memory>
#include <exception>
#include "AdjListVertex.h"
#include "Graph.h"

/**
 * @brief graph class
 */
class AdjListGraph : public Graph {
private:
    List<AdjListVertex> vertices;
    List<GraphEdge> adj_list;

public:
    AdjListGraph() = default;

    ~AdjListGraph() = default;

    explicit AdjListGraph(std::size_t number_of_vertices);

    bool insert_vertex(std::size_t id) override;

    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) override;

    const List<GraphEdge> incident_edges(std::size_t id) const override;

    List<AdjListVertex> get_vertices() const;

    List<GraphEdge> get_edges() const override;

    List<std::size_t> end_vertices(const GraphEdge &edge) const override;

    bool are_adjacent(std::size_t v, std::size_t u) const override;

    bool replace(const GraphEdge &edge, unsigned new_weight) override;

    bool replace(std::size_t old_id, std::size_t new_id) override;


    friend std::ostream &operator<<(std::ostream &os, const AdjListGraph &obj);


    bool remove_edge(const GraphEdge &edge);


    bool remove_vertex(std::size_t id);

};

#endif //STUD_PAMSI_GRAPHS_ADJLISTGRAPH_H
