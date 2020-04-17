//
// Created by lukasz-lap on 14.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
#define STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H

#include "List.h"
#include "GraphEdge.h"
#include "GraphVertex.h"
#include "Graph.h"


class AdjMatrixGraph : public Graph {
private:
    GraphEdge **adj_matrix;

public:
    AdjMatrixGraph();

    ~AdjMatrixGraph() override;

    explicit AdjMatrixGraph(std::size_t number_of_vertices);

    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) override;

    const List<GraphEdge> incident_edges(std::size_t id) const override;


    List<GraphEdge> get_edges() const override;


    bool are_adjacent(std::size_t v, std::size_t u) const override;

    friend std::ostream &operator<<(std::ostream &os, const AdjMatrixGraph &obj);

    bool remove_edge(const GraphEdge &edge) override;


    bool replace(const GraphEdge &edge, unsigned new_weight) override;


    void insert_vertex(int data) override;

    bool remove_vertex(std::size_t id) override;


};


#endif //STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
