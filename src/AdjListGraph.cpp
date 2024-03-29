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
        vertices.push_back(GraphVertex(i));

    }


}

/**
 * @brief Adds new vertex with given data
 * @param data data stored in vertex
 */
void AdjListGraph::insert_vertex(int data) {
    if (number_of_vertices == 0) {
        adj_list = new List<GraphEdge>[1];
        vertices.push_back(GraphVertex(0, data));
        ++number_of_vertices;
        return;
    }
    ++number_of_vertices;


    auto old_adj_list = adj_list;


    adj_list = new List<GraphEdge>[number_of_vertices];
    for (std::size_t i = 0; i < number_of_vertices - 1; ++i) {
        adj_list[i] = old_adj_list[i];
    }


    vertices.push_back(GraphVertex(number_of_vertices - 1, data));
    delete[] old_adj_list;
}

/**
 * @brief Allows adding new edge to the graph
 * @param from_id id of first vertex
 * @param to_id id of the second vertex
 * @param weight cost of the edge
 * @return false if id's out of bound
 */
bool AdjListGraph::insert_edge(std::size_t from_id, std::size_t to_id, unsigned weight) {
    if (from_id >= number_of_vertices ||
        to_id >= number_of_vertices) {
        return false;
    }
    auto edge = GraphEdge(from_id, to_id, weight);
    auto edge_reversed = GraphEdge(to_id, from_id, weight);

    if (adj_list[from_id].size() > adj_list[to_id].size()) {
        for (auto i: adj_list[to_id]) {
            if (i == edge_reversed) {
                return false;
            }
        }
    }
    if (adj_list[from_id].size() < adj_list[to_id].size()) {
        for (auto i: adj_list[from_id]) {
            if (i == edge) {
                return false;
            }
        }
    }


    adj_list[from_id].push_back(edge);
    adj_list[to_id].push_back(edge_reversed);

    return true;

}

/**
 * @brief Get incident edges to vertex with given id
 * @param id id of the vertex
 * @return list of incident edges or if not found
 *         list containing dummy edge (0,0,0)
 */
const List<GraphEdge> AdjListGraph::incident_edges(std::size_t id) const {
    if (id < number_of_vertices) {
        return adj_list[id];
    }
    List<GraphEdge> dummy_list;
    dummy_list.push_back(dummy);
    return dummy_list;
}


/**
 * @brief Get all edges of graph
 * @return List of edges in graph, or dummy edge if not found
 */
List<GraphEdge> AdjListGraph::get_edges() const {
    List<GraphEdge> ret_val;
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        for (auto j: adj_list[i]) {
            ret_val.push_back(j);
        }
    }
    //if do not have edges
    if (ret_val.is_empty()) {
        ret_val.push_back(dummy);
    }

    return ret_val;
}

/**
 * @brief Check if two vertices with given id's are incident
 * @param v first vertex id
 * @param u second vertex id
 * @return true if are incident, false if not, v or u out of bound, false if v == u
 */
bool AdjListGraph::are_adjacent(std::size_t v, std::size_t u) const {
    //out of bound
    if (v > number_of_vertices || u > number_of_vertices) {
        return false;
    }
    //equal indices
    if (v == u) {
        return false;
    }

    for (auto i: adj_list[v]) {
        for (auto j: adj_list[u]) {
            if (i.from_id == j.to_id && i.to_id == j.from_id) {
                return true; //if they have common edge
            }
        }
    }


    return false;

}

/**
 * @brief Replace edge with new edge with changed weight
 * @param edge old edge
 * @param new_weight new weight
 * @return true if replaced, false if not found given edge
 */
bool AdjListGraph::replace(const GraphEdge &edge, unsigned new_weight) {
    bool has_changed = false;
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        for (auto &j: adj_list[i]) {
            if (j == edge) {
                j.weight = new_weight;
                has_changed = true;
            }
        }
    }
    return has_changed;
}


/**
 * @brief Removes edge
 * @param edge given edge
 */
bool AdjListGraph::remove_edge(const GraphEdge &edge) {

    bool found = false;

    auto reversed = GraphEdge(edge.to_id, edge.from_id, edge.weight);
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        for (auto &j: adj_list[i]) {
            if (j == edge || j == reversed) {
                adj_list[i].pop_selected(j);
                found = true;
            }
        }


    }

    return found;


}

/**
 * @brief Removes vertex with given id and all edges coming from/to it
 * @param id vertex id
 */
bool AdjListGraph::remove_vertex(std::size_t id) {
    if (id >= number_of_vertices) {
        return false;
    }

    //remove all edges connected and change it's ids
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        for (auto &j: adj_list[i]) {
            if (j.from_id == id || j.to_id == id) {
                adj_list[i].pop_selected(j);
            }
            if (j.from_id > id) {
                --j.from_id;
            }
            if (j.to_id > id) {
                --j.to_id;
            }
        }
    }

    //change id's
    for (auto &i: vertices) {
        if (i.id == id) {
            vertices.pop_selected(i);
        }
        if (i.id > id) {
            --i.id;
        }
    }

    auto old_adj = adj_list;
    --number_of_vertices;
    adj_list = new List<GraphEdge>[number_of_vertices];
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        if (i == id) {
            continue;
        }
        adj_list[i] = old_adj[i];
    }


    return true;

}


AdjListGraph::~AdjListGraph() {
    delete[] adj_list;
}

AdjListGraph::AdjListGraph() : Graph() {
    adj_list = nullptr;
}

void AdjListGraph::print() const {
    for (std::size_t i = 0; i < this->number_of_vertices; ++i) {
        std::cout << i << this->adj_list[i] << std::endl;
    }


}















