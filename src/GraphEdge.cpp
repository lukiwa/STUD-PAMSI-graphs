//
// Created by lukasz-lap on 17.04.2020.
//
#include "GraphEdge.h"

/**
 * @brief initializes fields with 0
 */
GraphEdge::GraphEdge() {
    from_id = 0;
    to_id = 0;
    weight = 0;
}

/**
 * @brief Initializes fields with required data
 */
GraphEdge::GraphEdge(size_t fromId, size_t toId, unsigned int weight) :
        from_id(fromId), to_id(toId), weight(weight) {}


/**
 * @brief Checks whether two edges are equal
 * @param e edge
 * @return true if they are equal, false if they are not equal
 */
bool GraphEdge::operator==(const GraphEdge &e) {
    if (this->from_id == e.from_id) {
        if (this->to_id == e.to_id) {
            if (this->weight == e.weight) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Checks whether two edges are not equal
 * @param e edge
 * @return true if are not equal, false if they are equal
 */
bool GraphEdge::operator!=(const GraphEdge &e) {
    if (this->from_id == e.from_id) {
        if (this->to_id == e.to_id) {
            if (this->weight == e.weight) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Display edge
 */
std::ostream &operator<<(std::ostream &os, const GraphEdge &obj) {

    os << "{" <<
       obj.from_id << " " <<
       obj.to_id << " " <<
       obj.weight << "}";


    return os;
}



