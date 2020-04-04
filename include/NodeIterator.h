//
// Created by lukasz-lap on 03.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_NODEITERATOR_H
#define STUD_PAMSI_GRAPHS_NODEITERATOR_H

#include "Node.h"

template<typename T>
struct NodeIterator {
    NodeIterator(std::shared_ptr<Node<T>> curr) :
            curr(curr) {}


    NodeIterator &operator++() {
        curr = curr->next;
        return *this;
    }

    NodeIterator operator++(int) {
        NodeIterator ret_val = *this;
        ++(*this);
        return ret_val;
    }

    //  T *operator->() const { return &curr->data; }

    T &operator*() const { return curr->data; }

    bool operator!=(const NodeIterator<T> &iterator) const {
        return this->curr != iterator.curr;
    }


    friend std::ostream &operator<<(std::ostream &os, const NodeIterator<T> &iterator) {
        os << iterator.curr->data;
        return os;
    }

    std::shared_ptr<Node<T>> curr;
};


#endif //STUD_PAMSI_GRAPHS_NODEITERATOR_H
