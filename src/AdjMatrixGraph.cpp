//
// Created by lukasz-lap on 14.04.2020.
//

#include "AdjMatrixGraph.h"


//TODO
AdjMatrixGraph::~AdjMatrixGraph() {

}

AdjMatrixGraph::AdjMatrixGraph() {

}


/**
 * @brief Constructs graph object with given nubmer of vertices
 * @param number_of_vertices
 */
AdjMatrixGraph::AdjMatrixGraph(std::size_t number_of_vertices) :
        number_of_vertices(number_of_vertices) {


    this->number_of_vertices = number_of_vertices;
    GraphEdge dummy(0, 0, 0); //dummy edge, means no edges

    adj_matrix = new GraphEdge *[number_of_vertices];
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        adj_matrix[i] = new GraphEdge[number_of_vertices];
        vertices.push_back(AdjMatrixVertex{i});
        for (std::size_t j = 0; j < number_of_vertices; ++j) {
            adj_matrix[i][j] = dummy;
        }
    }
}

/**
 * Display graph
 */
std::ostream &operator<<(std::ostream &os, const AdjMatrixGraph &obj) {
    for (int i = 0; i < obj.number_of_vertices; ++i) {
        for (int j = 0; j < obj.number_of_vertices; ++j) {
            os << i << " " << j << " " << obj.adj_matrix[i][j] << std::endl;
        }
    }
    return os;
}

/**
 * @brief Insert new edge to the graph
 * @param from_id id of first vertex
 * @param to_id id of the second vertex
 * @param weight weight of the edge
 * @return true if added, false if vertices do not exists
 */
bool AdjMatrixGraph::insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) {
    if (from_id >= number_of_vertices ||
        to_id >= number_of_vertices) {
        return false;
    }
    if (!vertices.is_present(AdjMatrixVertex{from_id}) ||
        !vertices.is_present(AdjMatrixVertex{to_id})) {
        return false;
    }

    GraphEdge edge(from_id, to_id, weight);
    adj_matrix[from_id][to_id] = edge;
    adj_matrix[to_id][from_id] = edge;
    return true;

}
