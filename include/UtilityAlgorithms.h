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


/**
 * @brief Find a set of element i
 */
    int find(std::unique_ptr<Subset[]> &subsets, int i) {

        if (subsets[i].parent != i)
            subsets[i].parent = utility::find(subsets, subsets[i].parent);

        return subsets[i].parent;
    }

/**
 * @brief Do union of 2 sets
 */
    void union1(std::unique_ptr<Subset[]> &subsets, int x, int y) {
        int x_root = utility::find(subsets, x);
        int y_root = utility::find(subsets, y);


        if (subsets[x_root].rank < subsets[y_root].rank) {
            subsets[x_root].parent = y_root;
        } else if (subsets[x_root].rank > subsets[y_root].rank) {
            subsets[y_root].parent = x_root;
        } else {
            subsets[y_root].parent = x_root;
            subsets[x_root].rank++;
        }
    }

/**
 * @brief Sort list of given type
 * @tparam T type stored in list
 * @param list list (will be changed)
 */
    template<typename T>
    static void sort_list(List<T> &list) {
        auto array = new T[list.size()];
        int cnt = 0;
        for (auto i: list) {
            array[cnt++] = i;
        }

        cnt = 0;


        std::sort(array, array + list.size());

        for (auto &i: list) {
            i = array[cnt];
            cnt++;
        }
        delete[] array;
    }


    typedef std::pair<int32_t, List<std::size_t>> Pair;

    /**
     * @brief Create path from source vertex to given vertex
     * @param parent array of parents - edge previous to given vertex
     * @param vertices_numb number of vertices in the graph
     * @param result result structure
     */
    void CreatePath(std::size_t *parent, std::size_t vertices_numb, Pair *result) {
        for (int i = 0; i < vertices_numb; ++i) {
            result[i].second.push_back(i);
        }
        for (int i = 0; i < vertices_numb; ++i) {
            for (int j = i; j != 0; j = parent[j]) {
                result[i].second.push_front(parent[j]);
            }

        }

    }


    Pair *BellmanFord(Graph &graph, std::size_t source_id) {


        auto edges = graph.get_edges();
        std::size_t vertices_numb = graph.get_vertices().size();
        std::size_t edges_numb = edges.size();
        auto res = new Pair[vertices_numb];
        auto parent = new std::size_t[vertices_numb];
        parent[0] = 0;


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


        CreatePath(parent, vertices_numb, res);

        delete[] parent;
        return res;

    }


};


#endif //STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H
