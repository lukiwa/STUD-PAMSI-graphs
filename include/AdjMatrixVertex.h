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
    std::size_t id;
    int value;


    ~AdjMatrixVertex() = default;


    //TODO co z tym

    bool operator==(const AdjMatrixVertex &v) {
        return v.id == this->id && v.value == this->value;

    }


    bool operator!=(const AdjMatrixVertex &v) {
        return v.id != this->id && v.value != this->value;
    }


    friend std::ostream &operator<<(std::ostream &os, const AdjMatrixVertex &obj) {
        os << obj.id;
        return os;
    }


};

#endif //STUD_PAMSI_GRAPHS_ADJMATRIXVERTEX_H
