//
// Created by lukasz-lap on 25.04.2020.
//

#include "GraphBuilder.h"

/**
 * @brief Set type of graph to be generated
 * @param type graph type
 * @return builder ref
 */
GraphBuilder &GraphBuilder::SetType(GraphType type) {
    this->type = type;
    return *this;
}

/**
 * @brief Set size of the graph
 * @param size graph size
 * @return builder ref
 */
GraphBuilder &GraphBuilder::SetSize(std::size_t size) {
    switch (type) {
        case GraphType::LIST: {
            graph = std::make_unique<AdjListGraph>(size);
            break;
        }
        case GraphType::MATRIX: {
            graph = std::make_unique<AdjMatrixGraph>(size);
            break;
        }
    }
    generator = std::make_unique<RandomGraphGenerator>(*graph);

    generator->number_of_vertices = size;


    return *this;
}

/**
 * @brief Set density of the graph
 * @param density
 * @return builder ref
 */
GraphBuilder &GraphBuilder::SetDensity(double density) {
    generator->density = density;
    generator->number_of_edges = static_cast<std::size_t >(
            (density * generator->number_of_vertices *
             (generator->number_of_vertices - 1)) / 2);
    return *this;
}

/**
 * @brief Constructs random graph
 * @return unique graph
 */
std::unique_ptr<Graph> GraphBuilder::Build() {
    generator->Generate();
    return std::move(graph);
}
