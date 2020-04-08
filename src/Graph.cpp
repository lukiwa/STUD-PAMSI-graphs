//
// Created by lukasz-lap on 04.04.2020.
//

#include "Graph.h"


void Graph::add_vertex(int id) {
    vertices.push_back(Vertex{id});

}

bool Graph::add_single_edge(const Vertex &from, const Vertex &to, unsigned int weight) {
    if (!(vertices.is_present(from) && vertices.is_present(to))) {
        return false;
    }
    Edge new_edge{from, to, weight};
    Vertex new_from{from.id, from.edges};
    Vertex new_to{to.id, to.edges};


    edges.push_back(new_edge);
    new_from.edges.push_back(new_edge);
    new_to.edges.push_back(new_edge);


    vertices.update(from, new_from);
    vertices.update(to, new_to);

    //std::cout << vertices.front();

    return true;

}

Graph::Graph(std::size_t number_of_vertices) {
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        vertices.push_back(Vertex{static_cast<int>(i)});
    }
}
