//
// Created by lukasz-lap on 19.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H
#define STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H

#include "Subset.h"
#include "List.h"
#include <algorithm>
#include <memory>

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
};


#endif //STUD_PAMSI_GRAPHS_UTILITYALGORITHMS_H
