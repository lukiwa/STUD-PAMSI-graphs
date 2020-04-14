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
 * @brief Gets list of all vertices in graph
 * @return list of vertices
 */
const List<Vertex> &Graph::get_vertices() const {
    return vertices;
}

const List<Edge> &Graph::get_edges() const {
    return adj_list;
}

/**
 * @brief Get id's of end vertices of given edge
 * @param edge given edge at graph
 * @return 2 element list - (from_id, to_id)
 */
List<std::size_t> Graph::end_vertices(const Edge &edge) const {
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
std::size_t Graph::opposite(std::size_t vertex_id, const Edge &edge) const {
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
bool Graph::are_adjacent(std::size_t first_id, std::size_t second_id) const {
    if (first_id == second_id) {
        return false;
    }

    //if vertices exists
    if (!vertices.is_present(Vertex{first_id}) || !vertices.is_present(Vertex{second_id})) {
        return false;
    }
    Vertex vertex;

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
        if (adj_list.at(i).to_id == first_id && adj_list.at(i).from_id == second_id) {
            return true;
        }
        if (adj_list.at(i).from_id == first_id && adj_list.at(i).to_id == second_id) {
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
bool Graph::replace(const Edge &edge, unsigned new_weight) {
    for (auto i: adj_list) {
        if (i == edge) {
            i.weight = new_weight;
            return true;
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
bool Graph::replace(std::size_t old_id, std::size_t new_id) {
    if (!vertices.is_present(Vertex{old_id})) {
        return false;
    }
    Vertex vertex_old;
    Vertex vertex_new;

    for (auto &i: vertices) {
        if (i.data == old_id) {
            i.data = new_id;
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














