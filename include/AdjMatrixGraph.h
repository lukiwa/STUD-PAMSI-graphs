//
// Created by lukasz-lap on 14.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
#define STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H

#include "List.h"
#include "GraphEdge.h"
#include "Vertex.h"
#include "Graph.h"


class AdjMatrixGraph : public Graph {
private:
    GraphEdge dummy;
    GraphEdge **adj_matrix;

public:
    AdjMatrixGraph();

    //TOdo dokoncz konstruktor
    ~AdjMatrixGraph() override;

    explicit AdjMatrixGraph(std::size_t number_of_vertices);

    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) override;

    const List<GraphEdge> incident_edges(std::size_t id) const override;


    List<GraphEdge> get_edges() const override;


    bool are_adjacent(std::size_t v, std::size_t u) const override;

    friend std::ostream &operator<<(std::ostream &os, const AdjMatrixGraph &obj);

    bool remove_edge(const GraphEdge &edge) override;


    bool replace(const GraphEdge &edge, unsigned new_weight) override;

    bool replace(std::size_t old_data, std::size_t new_data) override;

    bool insert_vertex(std::size_t data) override;

    bool remove_vertex(std::size_t data) override;


};


#endif //STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
