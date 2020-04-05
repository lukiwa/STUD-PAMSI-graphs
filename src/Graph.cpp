//
// Created by lukasz-lap on 04.04.2020.
//

#include "Graph.h"


void Graph::add_vertex(int id) {
    vertices.push_back(Vertex{id});
}

bool Graph::add_edge(Vertex from, Vertex to, unsigned int weight) {
    return vertices.is_present(from) && vertices.is_present(to);


}

Graph::Graph(std::size_t number_of_vertices) {
    for (std::size_t i = 0; i < number_of_vertices; ++i) {
        vertices.push_back(Vertex{static_cast<int>(i)});
    }
}
