//
// Created by lukasz-lap on 16.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPH_H
#define STUD_PAMSI_GRAPHS_GRAPH_H

#include "GraphEdge.h"
#include "List.h"


class Graph {
    virtual bool insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) = 0;

    virtual const List<GraphEdge> incident_edges(std::size_t id) const = 0;


    virtual List<GraphEdge> get_edges() const = 0;

    virtual List<std::size_t> end_vertices(const GraphEdge &edge) const = 0;


    virtual bool are_adjacent(std::size_t v, std::size_t u) const = 0;


    virtual bool remove_edge(const GraphEdge &edge) = 0;


    virtual bool replace(const GraphEdge &edge, unsigned new_weight) = 0;

    virtual bool replace(std::size_t old_data, std::size_t new_data) = 0;

    virtual bool insert_vertex(std::size_t data) = 0;

    virtual bool remove_vertex(std::size_t data) = 0;

    /**
     * @brief Get opposite vertex of given edge
     * @param vertex_id one end of edge
     * @param edge given edge
     * @return second end of the edge
     */
    virtual std::size_t opposite(std::size_t vertex_id, const GraphEdge &edge) {
        if (vertex_id == edge.from_id) {
            return edge.to_id;
        }
        if (vertex_id == edge.to_id) {
            return edge.from_id;
        }
        //if does not have opposite (probably never reaches this point)
        throw (std::exception());
    }

    // GetVertices method

};


#endif //STUD_PAMSI_GRAPHS_GRAPH_H
