//
// Created by lukasz-lap on 02.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_NODE_H
#define STUD_PAMSI_GRAPHS_NODE_H

#include <bits/unique_ptr.h>

template<typename T>
struct Node {
    T data;
    Node *next;

};


#endif //STUD_PAMSI_GRAPHS_NODE_H
