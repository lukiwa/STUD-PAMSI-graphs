//
// Created by lukasz-lap on 05.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_ADJLISTEDGE_H
#define STUD_PAMSI_GRAPHS_ADJLISTEDGE_H

#include <iostream>
#include <sstream>

/**
 * @brief AdjListEdge of the graph
 */
struct AdjListEdge {
    std::size_t from_id;
    std::size_t to_id;
    unsigned weight;


    AdjListEdge(size_t fromId, size_t toId, unsigned int weight) : from_id(fromId), to_id(toId), weight(weight) {}

    bool operator==(const AdjListEdge &e) {
        if (this->from_id == e.from_id) {
            if (this->to_id == e.to_id) {
                if (this->weight == e.weight) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator!=(const AdjListEdge &e) {
        if (this->from_id == e.from_id) {
            if (this->to_id == e.to_id) {
                if (this->weight == e.weight) {
                    return false;
                }
            }
        }
        return true;
    }


    friend std::ostream &operator<<(std::ostream &os, const AdjListEdge &obj) {


        os << "{" <<
           obj.from_id << " " <<
           obj.to_id << " " <<
           obj.weight << "}";


        return os;
    }
};

#endif //STUD_PAMSI_GRAPHS_ADJLISTEDGE_H

