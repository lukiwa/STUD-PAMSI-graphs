//
// Created by lukasz-lap on 04.04.2020.
//

#include "AdjListGraph.h"


/**
 * Allows adding vertices during constructions
 * @param number_of_vertices
 */
AdjListGraph::AdjListGraph(std::size_t number_of_vertices) {
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        insert_vertex(i);
    }


}


/**
 * @brief Allows inserting vertex to the graph
 * @param id id of the new vertex
 * @return false if there is already vertex with given id
 */
bool AdjListGraph::insert_vertex(std::size_t id) {
    //if there is vertex with such id
    if (vertices.is_present(AdjListVertex{id})) {
        return false;
    }
    vertices.push_back(AdjListVertex{id});
    return true;
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
    if (!vertices.is_present(AdjListVertex{from_id}) || !vertices.is_present(AdjListVertex{to_id})) {
        return false;
    }

    auto new_edge = GraphEdge{from_id, to_id, weight};
    adj_list.push_back(new_edge);


    for (auto &i: vertices) {
        if (i.data == from_id) {
            i.edges.push_back(adj_list.back());
        }
    }

    for (auto &j: vertices) {
        if (j.data == to_id) {
            j.edges.push_back(adj_list.back());
        }
    }

    return true;

}

/**
 * @brief Returns list of incident edges to vertex with given id
 * @param id id of vertex
 * @return list of incident edges
 */
const List<GraphEdge> AdjListGraph::incident_edges(std::size_t id) const {
    List<GraphEdge> return_list;
    for (auto &i: vertices) {
        if (i.data == id) {
            return i.edges;
        }
    }

}

/**
 * @brief Gets list of all vertices in graph
 * @return list of vertices
 */
List<AdjListVertex> AdjListGraph::get_vertices() const {
    return vertices;
}

List<GraphEdge> AdjListGraph::get_edges() const {
    return adj_list;
}

/**
 * @brief Get id's of end vertices of given edge
 * @param edge given edge at graph
 * @return 2 element list - (from_id, to_id)
 */
List<std::size_t> AdjListGraph::end_vertices(const GraphEdge &edge) const {
    List<std::size_t> return_list;
    return_list.push_back(edge.from_id);
    return_list.push_back(edge.to_id);
    return return_list;
}

/**
 * @brief Gets opposite vertex
 * @param vertex vertex at one end od edge
 * @param edge edge connecting two vertices
 * @return id of second vertex
 */
std::size_t AdjListGraph::opposite(std::size_t vertex_id, const GraphEdge &edge) const {
    if (vertex_id == edge.from_id) {
        return edge.to_id;
    }
    if (vertex_id == edge.to_id) {
        return edge.from_id;
    }
    throw (std::exception());
}

/**
 * @brief Checks whether vertices with given id's are adjacent
 * @param first_id id of first vertex
 * @param second_id id of second vertex
 * @return true is are adjacent, false if there are not adjacent,
 *         id's are equal or vertices do not exists
 */
bool AdjListGraph::are_adjacent(std::size_t first_id, std::size_t second_id) const {

    if (first_id == second_id) {
        return false;
    }

    //if vertices exists
    if (!vertices.is_present(AdjListVertex{first_id}) || !vertices.is_present(AdjListVertex{second_id})) {
        return false;
    }
    AdjListVertex vertex;

    //find vertex with lesser edges
    for (auto &i: vertices) {
        if (i.data == first_id) {
            vertex = i;
        }
    }
    for (auto &j: vertices) {
        if (j.data == second_id) {
            if (vertex.edges.size() > j.edges.size()) {
                vertex = j;
            }
        }
    }


    for (auto i: vertex.edges) {
        if (i.to_id == first_id && i.from_id == second_id) {
            return true;
        }
        if (i.from_id == first_id && i.to_id == second_id) {
            return true;
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
    for (auto &i: adj_list) {
        if (i == edge) {
            i.weight = new_weight;
            return true;
        }
    }

    for (auto &i: vertices) {
        for (auto &j: i.edges) {
            if (j == edge) {
                j.weight = new_weight;
            }
        }
    }


    return false;
}

/**
 * @brief Replace vertex with old id with new id
 * @param old_id old id
 * @param new_id new id
 * @return  true if replaced, false if not found
 */
bool AdjListGraph::replace(std::size_t old_id, std::size_t new_id) {
    if (!vertices.is_present(AdjListVertex{old_id})) {
        return false;
    }

    for (auto &i: vertices) {
        if (i.data == old_id) {
            i.data = new_id;
        }
        for (auto &j: i.edges) {
            if (j.from_id == old_id) {
                j.from_id = new_id;

            }
            if (j.to_id == old_id) {
                j.to_id = new_id;
            }
        }
    }


    for (auto &i: adj_list) {
        if (i.from_id == old_id) {
            i.from_id = new_id;

        }
        if (i.to_id == old_id) {
            i.to_id = new_id;
        }
    }
    return true;

}

/**
 * @brief Display graph as adjacency list
 */
std::ostream &operator<<(std::ostream &os, const AdjListGraph &obj) {


    for (const auto &i: obj.vertices) {
        os << i.data << " ";
        for (auto j: i.edges) {
            os << j << " ";
        }
        os << std::endl;
    }


    return os;

}

/**
 * @brief Removes edge
 * @param edge given edge
 */
void AdjListGraph::remove_edge(const GraphEdge &edge) {
    //reverse edge, not directed graph
    auto rev_edge = GraphEdge{edge.to_id, edge.from_id, edge.weight};


    adj_list.pop_selected(edge);
    adj_list.pop_selected(rev_edge);

    for (auto &i: vertices) {
        i.edges.pop_selected(edge);
        i.edges.pop_selected(rev_edge);
    }


}

/**
 * @brief Removes vertex and all edges coming from/to it
 * @param data id of the vertex
 */
void AdjListGraph::remove_vertex(std::size_t data) {

    List<GraphEdge> edges_list;

    //find list of vertices of given object
    for (auto &i: vertices) {
        if (i.data == data) {
            edges_list = i.edges;
        }
    }

    //remove edges from vertices that contain it
    for (auto &i: vertices) {
        for (auto j: edges_list) {
            i.edges.pop_selected(j);
        }
    }

    //remove vertex from list
    vertices.pop_selected(AdjListVertex{data});


}















