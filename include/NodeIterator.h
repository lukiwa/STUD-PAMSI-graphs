//
// Created by lukasz-lap on 03.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_NODEITERATOR_H
#define STUD_PAMSI_GRAPHS_NODEITERATOR_H

#include "Node.h"

template<typename T>
/**
 * @brief Iterator for list
 * @tparam T type of data in list
 */
struct NodeIterator {
    std::shared_ptr<Node<T>> curr;

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


};


#endif //STUD_PAMSI_GRAPHS_NODEITERATOR_H
