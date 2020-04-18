//
// Created by lukasz-lap on 16.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPH_H
#define STUD_PAMSI_GRAPHS_GRAPH_H

#include "GraphEdge.h"
#include "List.h"
#include "GraphVertex.h"


class Graph {
protected:
    GraphEdge dummy;
    std::size_t number_of_vertices;
    List<GraphVertex> vertices;
public:
    Graph() {
        number_of_vertices = 0;
    }

    virtual ~Graph() = default;

    virtual bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) = 0;

    virtual const List<GraphEdge> incident_edges(std::size_t id) const = 0;


    virtual List<GraphEdge> get_edges() const = 0;


    virtual bool are_adjacent(std::size_t v, std::size_t u) const = 0;


    virtual bool remove_edge(const GraphEdge &edge) = 0;


    virtual bool replace(const GraphEdge &edge, unsigned new_weight) = 0;

    virtual void insert_vertex(int data) = 0;

    virtual bool remove_vertex(std::size_t id) = 0;


    virtual std::size_t opposite(std::size_t vertex_id, const GraphEdge &edge);


    List<GraphVertex> get_vertices() const;


    virtual List<std::size_t> end_vertices(const GraphEdge &edge);


    virtual bool vertex_replace(int old_data, int new_data);

};


#endif //STUD_PAMSI_GRAPHS_GRAPH_H
