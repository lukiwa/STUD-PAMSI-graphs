//
// Created by lukasz-lap on 04.04.2020.
//

#include "AdjListGraph.h"


/**
 * Allows adding vertices during constructions
 * @param number_of_vertices
 */
AdjListGraph::AdjListGraph(std::size_t number_of_vertices) {
    this->number_of_vertices = number_of_vertices;

    adj_list = new List<GraphEdge>[number_of_vertices];
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        vertices.push_back(Vertex(i));

    }


}


bool AdjListGraph::insert_vertex(std::size_t data) {
    vertices.push_back(Vertex(number_of_vertices - 1, static_cast<int>(data)));
}

/**
 * @brief Allows adding new edge to the graph
 * @param from_id id of first vertex
 * @param to_id id of the second vertex
 * @param weight cost of the edge
 * @return false if there aren't vertices with given id's
 */
bool AdjListGraph::insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) {
    //if there aren't vertices with given id's

    if (!vertices.is_present(Vertex(from_id)) || !vertices.is_present(Vertex(to_id))) {
        return false;
    }


    auto new_edge = GraphEdge(from_id, to_id, weight);
    adj_list[from_id].push_back(new_edge);
    adj_list[to_id].push_back(new_edge);

    return true;

}

//TODO
const List<GraphEdge> AdjListGraph::incident_edges(std::size_t id) const {


}


//TODO
List<GraphEdge> AdjListGraph::get_edges() const {

}


bool AdjListGraph::are_adjacent(std::size_t v, std::size_t u) const {
    if (!vertices.is_present(Vertex(u)) ||
        !vertices.is_present(Vertex(v)))


        return false;

}

/**
 * @brief Replace edge with new edge with changed weight
 * @param edge old edge
 * @param new_weight new weight
 * @return true if replaced, false if not found given edge
 */
bool AdjListGraph::replace(const GraphEdge &edge, unsigned new_weight) {

}

/**
 * @brief Replace vertex with old id with new id
 * @param old_id old id
 * @param new_id new id
 * @return  true if replaced, false if not found
 */
bool AdjListGraph::replace(std::size_t old_data, std::size_t new_data) {
    for (auto &i: vertices) {
        if (i.value == (int) old_data) {
            i.value = new_data;
            return true;
        }
    }
    return false;

}

/**
 * @brief Display graph as adjacency list
 */
std::ostream &operator<<(std::ostream &os, const AdjListGraph &obj) {
    for (int i = 0; i < obj.number_of_vertices; ++i) {
        os << i << obj.adj_list[i] << std::endl;
    }

    return os;

}

/**
 * @brief Removes edge
 * @param edge given edge
 */
bool AdjListGraph::remove_edge(const GraphEdge &edge) {
    //reverse edge, not directed graph
    auto reversed = GraphEdge(edge.to_id, edge.from_id, edge.weight);


    return true;


}

/** TODO usuwaj po id
 * @brief Removes vertex and all edges coming from/to it
 * @param data id of the vertex
 */
bool AdjListGraph::remove_vertex(std::size_t data) {
    if (data == 0) {
        return false;  //all vertices have default data =0
    }
    std::size_t id = 0;


    //find vertex and pop it and get it's id
    for (auto &i: vertices) {
        if (i.value == (int) data) {
            id = i.id;
            vertices.pop_selected(i);
        }
    };
    return true;

}


AdjListGraph::~AdjListGraph() {
    delete[] adj_list;
}

AdjListGraph::AdjListGraph() : Graph() {
    adj_list = nullptr;
}















