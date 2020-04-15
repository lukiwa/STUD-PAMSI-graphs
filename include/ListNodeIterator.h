//
// Created by lukasz-lap on 03.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_LISTNODEITERATOR_H
#define STUD_PAMSI_GRAPHS_LISTNODEITERATOR_H

#include "ListNode.h"

template<typename T>
/**
 * @brief Iterator for list
 * @tparam T type of data in list
 */
struct ListNodeIterator {
    std::shared_ptr<ListNode<T>> curr;

    ListNodeIterator(std::shared_ptr<ListNode<T>> curr) :
            curr(curr) {}


    ListNodeIterator &operator++() {
        curr = curr->next;
        return *this;
    }

    ListNodeIterator operator++(int) {
        ListNodeIterator ret_val = *this;
        ++(*this);
        return ret_val;
    }

    //  T *operator->() const { return &curr->data; }

    T &operator*() const { return curr->data; }

    bool operator!=(const ListNodeIterator<T> &iterator) const {
        return this->curr != iterator.curr;
    }


    friend std::ostream &operator<<(std::ostream &os, const ListNodeIterator<T> &iterator) {
        os << iterator.curr->data;
        return os;
    }


};


#endif //STUD_PAMSI_GRAPHS_LISTNODEITERATOR_H
