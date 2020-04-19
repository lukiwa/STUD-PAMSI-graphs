//
// Created by lukasz-lap on 19.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ALGORITHMSMST_H
#define STUD_PAMSI_GRAPHS_ALGORITHMSMST_H

#include "AdjMatrixGraph.h"
#include "AdjListGraph.h"
#include "List.h"
#include "UtilityAlgorithms.h"
#include <memory>

namespace mst {
    
    /**
     * @brief Find MST using Kruskal's algorithm
     * @param graph graph of which MST will be found
     * @return edges of MST
     */
    List<GraphEdge> KruskalMST(std::shared_ptr<Graph> graph) {
        std::size_t vertices_num = graph->get_vertices().size();
        auto edges = graph->get_edges();
        List<GraphEdge> result;
        std::size_t sorted_it = 0;

        //1
        utility::sort_list(edges);

        auto subsets = std::make_unique<Subset[]>(vertices_num * sizeof(Subset));

        for (std::size_t i = 0; i < vertices_num; ++i) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        //2
        while (sorted_it < edges.size()) {

            GraphEdge next_edge = edges.at(sorted_it++);

            int x = utility::find(subsets, next_edge.from_id);
            int y = utility::find(subsets, next_edge.to_id);


            if (x != y) {
                result.push_back(next_edge);
                utility::union1(subsets, x, y);
            }

        }
        return result;
    }
};

#endif //STUD_PAMSI_GRAPHS_ALGORITHMSMST_H
