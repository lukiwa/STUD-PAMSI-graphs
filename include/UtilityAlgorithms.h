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

namespace utility {

    //TODO implement own pair
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


    std::unique_ptr<Pair[]> BellmanFord(std::unique_ptr<Graph> &graph, std::size_t source_id) {

        auto edges = graph->get_edges();
        std::size_t vertices_numb = graph->get_vertices().size();
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

        //At this point negative cycle must have occured - throw exception:
        throw;

    }


};


#endif //STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H
