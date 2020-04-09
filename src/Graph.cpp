//
// Created by lukasz-lap on 04.04.2020.
//

#include "Graph.h"

bool Graph::insert_vertex(std::size_t data) {
    try {
        vertices.push_back(Vertex{data});
    }
    catch (std::exception &e) {
        return false;
    }


    return true;
}

bool Graph::insert_edge(std::size_t from, std::size_t to, unsigned weight) {

    std::size_t new_edge_index = number_of_edges++;
    adj_list.push_back(Edge{from, to, weight});



    for (auto &i: vertices) {
        if (i.data == from) {
            i.edges.push_back(new_edge_index);
        }
    }

    for (auto &j: vertices) {
        if (j.data == to) {
            j.edges.push_back(new_edge_index);
        }
    }

    return true;

}


std::ostream &operator<<(std::ostream &os, const Graph &obj) {


    for (const auto &i: obj.vertices) {
        os << i.data;
        for (auto j: i.edges) {
            os << obj.adj_list.at(j);
        }
        os << std::endl;
    }


    return os;

/*
    os << obj.vertices << std::endl;
    os << obj.adj_list;
    */
}

//TODO not working
bool Graph::remove_edge(const Edge &edge) {

}

//TODO not working
bool Graph::remove_vertex(std::size_t data) {


}

Graph::Graph() {
    number_of_edges = 0;
}






