//
// Created by lukasz-lap on 02.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_NODE_H
#define STUD_PAMSI_GRAPHS_NODE_H

#include <memory>

template<typename T>
struct Node {
    Node(const T &data, const std::shared_ptr<Node<T>> &next) :
            data(data),
            next(next) {}

    T data;
    std::shared_ptr<Node<T>> next;


};


#endif //STUD_PAMSI_GRAPHS_NODE_H
