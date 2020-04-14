//
// Created by lukasz-lap on 14.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJMATRIXVERTEX_H
#define STUD_PAMSI_GRAPHS_ADJMATRIXVERTEX_H

#include <iostream>
#include <sstream>


/**
 * @brief vertex of the graph
 */
struct AdjMatrixVertex {
    std::size_t key;
    int value;


    ~AdjMatrixVertex() = default;


    //TODO co z tym
    /*
    bool operator==(const AdjListVertex &v) {
        return v.data == this->data;
    }


    bool operator!=(const AdjListVertex &v) {
        return v.data != this->data;
    }


    friend std::ostream &operator<<(std::ostream &os, const AdjListVertex &obj) {
        os << obj.data;
        return os;
    }

    */

};

#endif //STUD_PAMSI_GRAPHS_ADJMATRIXVERTEX_H
