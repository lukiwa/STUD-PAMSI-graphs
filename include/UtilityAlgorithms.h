//
// Created by lukasz-lap on 19.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H
#define STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H


#include "List.h"
#include "Graph.h"
#include <algorithm>
#include <memory>
#include <cmath>
#include <fstream>
#include "MyPair.h"
#include "GraphBuilder.h"
#include <stdexcept>

namespace utility {

    typedef MyPair<int32_t, List<std::size_t>> Pair;

    /**
     * @brief Create path from source vertex to given vertex
     * @param parent array of parents - edge previous to given vertex
     * @param vertices_numb number of vertices in the graph
     * @param result result structure
     */
    void
    CreatePath(std::unique_ptr<std::size_t[]> &parent,
               std::size_t vertices_numb,
               std::unique_ptr<Pair[]> &result,
               std::size_t source_vertex_id) {
        for (std::size_t i = 0; i < vertices_numb; ++i) {
            result[i].second.push_back(i);
        }
        for (std::size_t i = 0; i < vertices_numb; ++i) {
            for (std::size_t j = i; j != source_vertex_id; j = parent[j]) {
                result[i].second.push_front(parent[j]);
            }
        }

    }

    /**
     * @brief Find shortest path between each vertex of the graph
     * @param graph
     * @param source_id
     * @return Array of pairs where pair[n].first is cost
     *         pair[n].second is route to n vertex
     */
    std::unique_ptr<Pair[]> BellmanFord(Graph &graph, std::size_t source_id) {

        auto edges = graph.get_edges();
        std::size_t vertices_numb = graph.get_vertices().size();
        auto res = std::make_unique<Pair[]>(vertices_numb);
        auto parent = std::make_unique<std::size_t[]>(vertices_numb);


        for (std::size_t i = 0; i < vertices_numb; ++i) {
            res[i].first = INT32_MAX;
        }
        res[source_id].first = 0;

        for (std::size_t i = 1; i < vertices_numb; ++i) {
            bool has_relaxed = false;
            for (auto e: edges) {
                std::size_t u = e.from_id;
                std::size_t v = e.to_id;
                int32_t weight = e.weight;

                if (res[u].first != INT32_MAX && res[u].first + weight < res[v].first) {
                    res[v].first = res[u].first + weight;
                    parent[v] = u;
                    has_relaxed = true;

                }
            }
            if (!has_relaxed) {
                CreatePath(parent, vertices_numb, res, source_id);
                return res;
            }
        }

        //At this point negative cycle must have occurred - throw exception:
        throw std::logic_error("Negative cycle found! (Bellman-Ford algorithm)");

    }

    /**
     * @brief Read graph data from file and create it
     * @param type type of the graph to be created
     * @param source_vertex source vertex to find shortest path
     * @return created graph
     */
    std::unique_ptr<Graph> ReadGraphFromFile(GraphType type, int &source_vertex) {


        const std::string path = "graph_reading/graph.txt"; //default file_path
        List<int> first_line_data;
        List<GraphEdge> edges;
        std::unique_ptr<Graph> graph;

        //open file
        std::ifstream stream;
        stream.open(path.c_str(), std::ios::out | std::ios::app);
        if (stream.fail()) {
            std::cout << "Failed to open file!" << std::endl;
            throw;
        }

        //read first line
        std::string first_line;
        std::getline(stream, first_line);
        std::stringstream first_line_stream(first_line);
        int value;

        while (first_line_stream >> value) {
            first_line_data.push_back(value);
        }
        first_line.erase();


        //create graph with parameters
        switch (type) {
            case GraphType::LIST: {
                graph = std::make_unique<AdjListGraph>
                        (first_line_data.at(1));
                break;
            }
            case GraphType::MATRIX: {
                graph = std::make_unique<AdjMatrixGraph>
                        (first_line_data.at(1));
                break;
            }
        }
        source_vertex = first_line_data.at(2);




        //read edges
        std::string line;
        while (std::getline(stream, line)) {

            List<int> values;
            std::stringstream line_stream(line);
            std::size_t tmp;

            while (line_stream >> tmp) {
                values.push_back(tmp);
            }
            graph->insert_edge(values.at(0), values.at(1), values.at(2));
        }

        return graph;
    }


};


#endif //STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H
