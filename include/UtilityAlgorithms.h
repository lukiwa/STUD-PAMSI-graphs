//
// Created by lukasz-lap on 19.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H
#define STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H

#include "Subset.h"
#include "List.h"
#include <algorithm>
#include <memory>
#include <cmath>

namespace utility {


    typedef std::pair<int32_t, List<std::size_t>> Pair;

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
     * @brief Doubles edges in graph to make it undirected
     *        Creates new edge with swapped vertices id's for each existing vertex
     * @param edges edges in graph
     * @return list of doubled edges
     */
    List<GraphEdge> MakeUndirected(const List<GraphEdge> &edges) {
        List<GraphEdge> ret_val;

        for (auto i: edges) {
            ret_val.push_back(i);
            ret_val.push_back(GraphEdge(i.to_id, i.from_id, i.weight));
        }
        return ret_val;
    }


    std::unique_ptr<Pair[]> BellmanFord(Graph &graph, std::size_t source_id) {

        auto edges = MakeUndirected(graph.get_edges());
        std::size_t vertices_numb = graph.get_vertices().size();
        std::size_t edges_numb = edges.size();
        auto res = std::make_unique<Pair[]>(vertices_numb);
        auto parent = std::make_unique<std::size_t[]>(vertices_numb);


        for (std::size_t i = 0; i < vertices_numb; i++) {
            res[i].first = INT32_MAX;
        }
        res[source_id].first = 0;

        for (std::size_t i = 1; i < vertices_numb; ++i) {
            for (std::size_t j = 0; j < edges_numb; ++j) {
                std::size_t u = edges.at(j).from_id;
                std::size_t v = edges.at(j).to_id;
                int32_t weight = edges.at(j).weight;
                if (res[u].first != INT32_MAX && res[u].first + weight < res[v].first) {
                    res[v].first = res[u].first + weight;

                    parent[v] = u;

                }
            }
        }

        //negative weight cycle check
        for (std::size_t i = 0; i < edges_numb; ++i) {
            std::size_t u = edges.at(i).from_id;
            std::size_t v = edges.at(i).to_id;
            int32_t weight = edges.at(i).weight;
            if (res[u].first != INT32_MAX && res[u].first + weight < res[v].first) {
                throw;
            }
        }

        CreatePath(parent, vertices_numb, res, source_id);


        return res;

    }


};


#endif //STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H
