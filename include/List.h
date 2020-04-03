//
// Created by lukasz-lap on 02.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_LIST_H
#define STUD_PAMSI_GRAPHS_LIST_H

#include "Node.h"
#include "NodeIterator.h"



//TODO

//copy
//destructor
//find
//insert after/before node


template<typename T>
class List {
private:
    Node<T> *head;
    Node<T> *tail;
    std::size_t count;

public:

    List() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    /**
     * Returns counted nodes in the list
     * @return  nodes in list
     */
    std::size_t size() {
        return count;
    }

    /**
     * Checks if the list is empty
     * @return true if the list is empty, false otherwise
     */
    bool is_empty() {
        return count == 0;
    }

    /**
     * Gets data from the front of the list
     * @return requested data
     */
    T front() {
        if (head != nullptr) {
            return head->data;
        }
    }

    /**
     * Gets data from the back of the list
     * @return requested data
     */
    T back() {
        if (tail != nullptr) {
            return tail->data;
        }
    }


    /**
     * For ranged loops
     * @return head of the list
     */
    NodeIterator<T> begin() const {
        return NodeIterator<T>(head);
    }

    /**
     * For ranged loops
     * @return very end of the list which is nullptr
     */
    NodeIterator<T> end() const {
        return NodeIterator<T>(nullptr);;
    }


    /**
     * Adds element at the front
     * @param data data to be inserted
     */
    void push_front(T data) {
        auto *temp = new Node<T>();
        temp->data = data;
        temp->next = head;
        head = temp;
        ++count;
    }

    /**
     * Adds data at the back
     * @param data data to be inserted
     */
    void push_back(T data) {
        auto temp = new Node<T>();
        temp->data = data;
        temp->next = nullptr;
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
        ++count;
    }


    /**
     * Removes first element
     */
    void pop_front() {
        if (head == nullptr)
            return;

        // Move the head pointer to the next node
        auto curr = head;
        head = head->next;


        delete curr;
        --count;
    }

    /**
     * Removes last element
     */
    void pop_back() {
        if (head == nullptr) {
            --count;
            return;
        }


        if (head->next == nullptr) {
            delete head;
            --count;
            return;
        }


        Node<T> *curr = head;
        while (curr->next->next != nullptr)
            curr = curr->next;


        delete (curr->next);


        curr->next = nullptr;
        --count;

    }

    friend std::ostream &operator<<(std::ostream &os, const List<T> &obj) {
        for (auto it = obj.begin(); it != obj.end(); ++it) {
            os << it << " ";
        }
        return os;
    }
};


#endif //STUD_PAMSI_GRAPHS_LIST_H
