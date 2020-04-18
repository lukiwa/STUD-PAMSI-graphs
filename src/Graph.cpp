//
// Created by lukasz-lap on 17.04.2020.
//

#include "Graph.h"

/**
     * @brief Get opposite vertex of given edge
     * @param vertex_id one end of edge
     * @param edge given edge
     * @return second end of the edge
     */
std::size_t Graph::opposite(std::size_t vertex_id, const GraphEdge &edge) {
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
List<GraphVertex> Graph::get_vertices() const {
    return vertices;
}

/**
 * @brief Get end vertices of given edge
 * @param edge given edge
 * @return list of end vertices
 */
List<std::size_t> Graph::end_vertices(const GraphEdge &edge) {
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
bool Graph::vertex_replace(int old_data, int new_data) {
    for (auto &i: vertices) {
        if (i.value == old_data) {
            i.value = new_data;
            return true;
        }
    }
    return false;
}