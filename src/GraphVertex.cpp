//
// Created by lukasz-lap on 17.04.2020.
//
#include "GraphVertex.h"

/**
 * @brief Constructs vertex with given id with default field value = 0
 * @param id id of the vertex
 */
GraphVertex::GraphVertex(size_t id) : id(id) { value = 0; }

/**
 * @brief Constructs vertex with given id and value
 * @param id id of the vertex
 * @param value data stored in vertex
 */
GraphVertex::GraphVertex(size_t id, int value) : id(id), value(value) {}


/**
 * @brief Check whether two vertices are equal
 * @param v vertex
 * @return true if are equal, false otherwise
 */
bool GraphVertex::operator==(const GraphVertex &v) {
    return v.id == this->id && v.value == this->value;

}

/**
 * @brief Check whether two vertices are NOT equal
 * @param v vertex
 * @return true if are not equal, false otherwise
 */
bool GraphVertex::operator!=(const GraphVertex &v) {
    return v.id != this->id && v.value != this->value;
}

/**
 * @brief Display vertex as pair id-value
 */
std::ostream &operator<<(std::ostream &os, const GraphVertex &obj) {
    os << "{" << obj.id << " " << obj.value << "}";
    return os;
}

