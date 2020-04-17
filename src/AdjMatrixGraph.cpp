//
// Created by lukasz-lap on 14.04.2020.
//

#include "AdjMatrixGraph.h"

AdjMatrixGraph::AdjMatrixGraph() : Graph() {
    adj_matrix = nullptr;
    *adj_matrix = nullptr;
}

//TODO dokoncz konstruktor
AdjMatrixGraph::~AdjMatrixGraph() {

}


/**
 * @brief Constructs graph object with given nubmer of vertices
 * @param number_of_vertices
 */
AdjMatrixGraph::AdjMatrixGraph(std::size_t number_of_vertices) {
    this->number_of_vertices = number_of_vertices;

    adj_matrix = new GraphEdge *[number_of_vertices];
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        adj_matrix[i] = new GraphEdge[number_of_vertices];
        vertices.push_back(Vertex(i));
        for (std::size_t j = 0; j < number_of_vertices; ++j) {
            adj_matrix[i][j] = dummy;
        }
    }
}

/**
 * Display graph
 */
std::ostream &operator<<(std::ostream &os, const AdjMatrixGraph &obj) {
    for (std::size_t i = 0; i < obj.number_of_vertices; ++i) {
        for (std::size_t j = 0; j < obj.number_of_vertices; ++j) {
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
    /*
    if (!vertices.is_present(Vertex{from_id}) ||
        !vertices.is_present(Vertex{to_id})) {
        return false;
    }
     */

    GraphEdge edge(from_id, to_id, weight);
    adj_matrix[from_id][to_id] = edge;
    adj_matrix[to_id][from_id] = edge;
    return true;

}

/**
 * @brief Get list of edges incident to vertex with given id
 * @param id id of the vertex
 * @return incident edges
 */
const List<GraphEdge> AdjMatrixGraph::incident_edges(std::size_t id) const {
    List<GraphEdge> ret_val;
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        if (adj_matrix[id][i] != GraphEdge(0, 0, 0)) {
            ret_val.push_back(adj_matrix[id][i]);
        }

    }

    //if edges not found
    if (ret_val.is_empty()) {
        ret_val.push_back(dummy);
    }
    return ret_val;
}

/**
 * @brief Get all edges in graph
 * @return list of edges in graph
 */
List<GraphEdge> AdjMatrixGraph::get_edges() const {
    List<GraphEdge> ret_val;
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        for (std::size_t j = 0; j < number_of_vertices; ++j) {
            if (!ret_val.is_present(adj_matrix[i][j]) && adj_matrix[i][j] != dummy) {
                ret_val.push_back(adj_matrix[i][j]);
            }
        }
    }
    if (ret_val.is_empty()) {
        ret_val.push_back(dummy);
    }
    return ret_val;

}


/**
 * @brief Checks if 2 vertices are adjacent
 * @param v id of first vertex
 * @param u id of second vertex
 * @return true if are adjacent, false if vertices do not exist, or id's are out of bound
 */
bool AdjMatrixGraph::are_adjacent(std::size_t v, std::size_t u) const {
    if (v >= number_of_vertices || u >= number_of_vertices) {
        return false;
    }

    if (!vertices.is_present(Vertex(v)) || !vertices.is_present(Vertex(u))) {
        return false;
    }


    return adj_matrix[v][u] != dummy || adj_matrix[u][v] != dummy;
}

/**
 * @brief Replaces given edge with dummy edge
 * @param edge edge that needs to be deleted
 */
bool AdjMatrixGraph::remove_edge(const GraphEdge &edge) {
    if (!vertices.is_present(Vertex(edge.from_id)) ||
        !vertices.is_present(Vertex(edge.to_id))) {
        return false;
    }
    GraphEdge reversed(edge.to_id, edge.from_id, edge.weight);

    if (adj_matrix[edge.from_id][edge.to_id] == edge ||
        adj_matrix[edge.from_id][edge.to_id] == reversed) {

        adj_matrix[edge.from_id][edge.to_id] = dummy;
    }
    if (adj_matrix[edge.to_id][edge.from_id] == edge ||
        adj_matrix[edge.to_id][edge.from_id] == reversed) {

        adj_matrix[edge.to_id][edge.from_id] = dummy;
    }
    return true;

}


/**
 * @brief Change weight of the
 * @param edge
 * @param new_weight
 * @return true if replaced, false if vertices connected to edge do not exists
 */
bool AdjMatrixGraph::replace(const GraphEdge &edge, unsigned new_weight) {
    if (!vertices.is_present(Vertex(edge.from_id)) ||
        !vertices.is_present(Vertex(edge.to_id))) {
        return false;
    }


    if (adj_matrix[edge.from_id][edge.to_id] == edge) {
        adj_matrix[edge.from_id][edge.to_id].weight = new_weight;
    }

    if (adj_matrix[edge.to_id][edge.from_id] == edge) {
        adj_matrix[edge.to_id][edge.from_id].weight = new_weight;
    }
    return true;
}

/**
 * @brief Adds new vertex with given data
 * @param data data stored inside vertex
 * @return true if added
 */
bool AdjMatrixGraph::insert_vertex(std::size_t data) {
    ++number_of_vertices;
    vertices.push_back(Vertex(number_of_vertices - 1, static_cast<int>(data)));
    auto old_adj_matrix = adj_matrix;

    adj_matrix = new GraphEdge *[number_of_vertices];
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        adj_matrix[i] = new GraphEdge[number_of_vertices];
        for (std::size_t j = 0; j < number_of_vertices; ++j) {
            adj_matrix[i][j] = dummy;
        }
    }


    for (std::size_t i = 0; i < number_of_vertices - 1; ++i) {
        for (std::size_t j = 0; j < number_of_vertices - 1; ++j) {
            adj_matrix[i][j] = old_adj_matrix[i][j];
        }
    }

    return true;
}

/** TODO usuwaj po id
 * @brief Remove first vertex with given data
 * @param data data stored in vertex
 * @return true if removed, false otherwise
 */
bool AdjMatrixGraph::remove_vertex(std::size_t data) {

    std::size_t id = 0;


    //find vertex and pop it
    for (auto &i: vertices) {
        if (i.value == (int) data) {
            id = i.id;
            vertices.pop_selected(i);
        }
    }
    //if vertex with such data was not found
    if (id == 0) {
        return false;
    }
    --number_of_vertices;

    //change id's after removed vertex
    for (auto &i: vertices) {
        if (i.id > id) {
            --i.id;
        }
    }

    //remove all edges to or from that vertex
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        for (std::size_t j = 0; j < number_of_vertices; ++j) {
            if (adj_matrix[i][j].to_id == id || adj_matrix[i][j].from_id == id) {
                adj_matrix[i][j] = dummy;
            }
        }
    }

    //allocate new matrix
    auto old_adj_matrix = adj_matrix;
    adj_matrix = new GraphEdge *[number_of_vertices];
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        adj_matrix[i] = new GraphEdge[number_of_vertices];
        for (std::size_t j = 0; j < number_of_vertices; ++j) {
            adj_matrix[i][j] = dummy;
        }
    }


    //no changes in matrix to that id
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        if (i == id) { continue; }
        for (std::size_t j = 0; j < number_of_vertices; ++j) {
            if (j == id) { continue; }
            old_adj_matrix[i][j] = adj_matrix[i][j];
        }
    }


    return true;

}

/**
 * @brief Replace data of vertex (first found)
 * @param old_data prev data stored in vertex
 * @param new_data new data stored in vertex
 * @return true if replaced, false otherwise
 */
bool AdjMatrixGraph::replace(std::size_t old_data, std::size_t new_data) {

    for (auto &i: vertices) {
        if (i.value == (int) old_data) {
            i.value = new_data;
            return true;
        }
    }
    return false;
}
