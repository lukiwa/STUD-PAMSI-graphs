//
// Created by lukasz-lap on 14.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
#define STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H

#include "List.h"
#include "GraphEdge.h"
#include "AdjMatrixVertex.h"

class AdjMatrixGraph {
private:
    GraphEdge dummy;
    std::size_t number_of_vertices;
    List<AdjMatrixVertex> vertices;
    GraphEdge **adj_matrix; //

public:
    //TODO
    AdjMatrixGraph();

    ~AdjMatrixGraph();

    explicit AdjMatrixGraph(std::size_t number_of_vertices);


    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight);

    const List<GraphEdge> incident_edges(std::size_t id) const;


    List<GraphEdge> get_edges() const;

    List<std::size_t> end_vertices(const GraphEdge &edge) const;

    std::size_t opposite(std::size_t vertex_id, const GraphEdge &edge) const;

    bool are_adjacent(std::size_t v, std::size_t u) const;

    friend std::ostream &operator<<(std::ostream &os, const AdjMatrixGraph &obj);

    void remove_edge(const GraphEdge &edge);

    List<AdjMatrixVertex> get_vertices() const;


    //TODO
    bool replace(const GraphEdge &edge, unsigned new_weight);

    bool replace(std::size_t old_id, std::size_t new_id);

    bool insert_vertex(std::size_t id);

    void remove_vertex(std::size_t id);


};


#endif //STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
