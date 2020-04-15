//
// Created by lukasz-lap on 02.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_LISTNODE_H
#define STUD_PAMSI_GRAPHS_LISTNODE_H

#include <memory>

template<typename T>
/**
 * @brief ListNode of the list
 * @tparam T type of elements stored in list
 */
struct ListNode {
    ListNode(const T &data, const std::shared_ptr<ListNode<T>> &next) :
            data(data),
            next(next) {}

    T data;
    std::shared_ptr<ListNode<T>> next;


};


#endif //STUD_PAMSI_GRAPHS_LISTNODE_H
