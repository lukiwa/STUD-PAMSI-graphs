//
// Created by lukasz-lap on 02.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_NODE_H
#define STUD_PAMSI_GRAPHS_NODE_H

#include <memory>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;


};


#endif //STUD_PAMSI_GRAPHS_NODE_H
