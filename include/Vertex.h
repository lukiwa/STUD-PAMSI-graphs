//
// Created by lukasz-lap on 14.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_VERTEX_H
#define STUD_PAMSI_GRAPHS_VERTEX_H

#include <iostream>
#include <sstream>

//TODO przenies do cpp
/**
 * @brief vertex of the graph
 */
struct Vertex {
    std::size_t id;
    int value;


    explicit Vertex(size_t id) : id(id) { value = 0; }

    Vertex(size_t id, int value) : id(id), value(value) {}

    ~Vertex() = default;


    bool operator==(const Vertex &v) {
        return v.id == this->id && v.value == this->value;

    }


    bool operator!=(const Vertex &v) {
        return v.id != this->id && v.value != this->value;
    }


    friend std::ostream &operator<<(std::ostream &os, const Vertex &obj) {
        os << "{" << obj.id << " " << obj.value << "}";
        return os;
    }


};

#endif //STUD_PAMSI_GRAPHS_VERTEX_H
