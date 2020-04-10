//
// Created by lukasz-lap on 04.04.2020.
//

#include "Graph.h"

/**
 * @brief Constructor, sets initial number of edges as 0
 */
Graph::Graph() {
    number_of_edges = 0;
}

/**
 * @brief Allows inserting vertex to the graph
 * @param id id of the new vertex
 * @return false if there is already vertex with given id
 */
bool Graph::insert_vertex(std::size_t id) {
    //if there is vertex with such id
    if (vertices.is_present(Vertex{id})) {
        return false;
    }
    vertices.push_back(Vertex{id});
    return true;
}

/**
 * @brief Allows adding new edge to the graph
 * @param from_id id of first vertex
 * @param to_id id of the second vertex
 * @param weight cost of the edge
 * @return false if there aren't vertices with given id's
 */
bool Graph::insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) {
    //if there aren't vertices with given id's
    if (!vertices.is_present(Vertex{from_id}) || !vertices.is_present(Vertex{to_id})) {
        return false;
    }

    std::size_t new_edge_index = number_of_edges++;
    adj_list.push_back(Edge{from_id, to_id, weight});


    for (auto &i: vertices) {
        if (i.data == from_id) {
            i.edges.push_back(new_edge_index);
        }
    }

    for (auto &j: vertices) {
        if (j.data == to_id) {
            j.edges.push_back(new_edge_index);
        }
    }

    return true;

}

/**
 * @brief Returns list of incident edges to vertex with given id
 * @param id id of vertex
 * @return list of incident edges
 */
List<Edge> Graph::incident_edges(std::size_t id) const {
    List<Edge> return_list;
    for (auto &i: vertices) {
        if (i.data == id) {
            for (auto j: i.edges) {
                return_list.push_back(adj_list.at(j));
            }
        }
    }
    return return_list;
}

/**
 * @brief Display graph as adjency list
 */
std::ostream &operator<<(std::ostream &os, const Graph &obj) {


    for (const auto &i: obj.vertices) {
        os << i.data << " ";
        for (auto j: i.edges) {
            os << obj.adj_list.at(j) << " ";
        }
        os << std::endl;
    }


    return os;

}

//TODO not working
bool Graph::remove_edge(const Edge &edge) {

}

//TODO not working
bool Graph::remove_vertex(std::size_t data) {


}








