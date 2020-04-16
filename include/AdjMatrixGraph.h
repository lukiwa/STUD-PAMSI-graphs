//
// Created by lukasz-lap on 14.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
#define STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H

#include "List.h"
#include "GraphEdge.h"
#include "AdjMatrixVertex.h"
#include "Graph.h"


class AdjMatrixGraph : public Graph {
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


    bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) override;

    const List<GraphEdge> incident_edges(std::size_t id) const override;


    List<GraphEdge> get_edges() const override;

    List<std::size_t> end_vertices(const GraphEdge &edge) const override;


    bool are_adjacent(std::size_t v, std::size_t u) const override;

    friend std::ostream &operator<<(std::ostream &os, const AdjMatrixGraph &obj) ;

    bool remove_edge(const GraphEdge &edge) override;

    List<AdjMatrixVertex> get_vertices() const ;


    bool replace(const GraphEdge &edge, unsigned new_weight) override;

    bool replace(std::size_t old_data, std::size_t new_data) override;

    bool insert_vertex(std::size_t data) override;

    bool remove_vertex(std::size_t data) override;


};


#endif //STUD_PAMSI_GRAPHS_ADJMATRIXGRAPH_H
