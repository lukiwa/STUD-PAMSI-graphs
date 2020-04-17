//
// Created by lukasz-lap on 16.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPH_H
#define STUD_PAMSI_GRAPHS_GRAPH_H

#include "GraphEdge.h"
#include "List.h"
#include "Vertex.h"

//TODO przenies do cpp
class Graph {
protected:
    GraphEdge dummy;
    std::size_t number_of_vertices;
    List<Vertex> vertices;
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

    /**
     * @brief Get list of vertices
     * @return list of vertices
     */
    List<Vertex> get_vertices() const {
        return vertices;
    }

    /**
     * @brief Get end vertices of given edge
     * @param edge given edge
     * @return list of end vertices
     */
    virtual List<std::size_t> end_vertices(const GraphEdge &edge) {
        List<std::size_t> return_list;
        return_list.push_back(edge.from_id);
        return_list.push_back(edge.to_id);
        return return_list;
    }

    /**
     * @brief Replace data stored in vertex
     * @param old_data old data inside vertex
     * @param new_data new data inside vertex
     * @return true if replaced, false if vertex with such data do not exist
     */
    virtual bool replace(int old_data, int new_data) {
        for (auto &i: vertices) {
            if (i.value == old_data) {
                i.value = new_data;
                return true;
            }
        }
        return false;
    }

};


#endif //STUD_PAMSI_GRAPHS_GRAPH_H
