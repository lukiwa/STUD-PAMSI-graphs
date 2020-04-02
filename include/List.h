//
// Created by lukasz-lap on 02.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_LIST_H
#define STUD_PAMSI_GRAPHS_LIST_H

#include "Node.h"

template<typename T>
class List {
private:
    Node<T> *head;
    Node<T> *tail;

public:

    List() {
        head = nullptr;
        tail = nullptr;
    }

//TODO
    std::size_t size() {}

    bool empty() {}

    T find() {}

    T front() {}

    T back() {}

    //copy
    //destructor
    // << operator
    //begin
    //end
    //fix remove methods
    //insert after/before node



    /**
     * Adds element at the front
     * @param data data to be inserted
     */
    void push_front(T data) {
        auto *temp = new Node<T>();
        temp->data = data;
        temp->next = head;
        head = temp;
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
            temp = nullptr;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    /**
     * Insert data at given position
     * @param pos position
     * @param data data to be inserted
     */
    void insert(std::size_t pos, T data) {
        auto prev = new Node<T>();
        auto curr = new Node<T>();
        auto temp = new Node<T>();
        curr = head;
        for (std::size_t i = 1; i < pos; ++i) {
            prev = curr;
            curr = curr->next;
        }
        temp->data = data;
        prev->next = temp;
        temp->next = curr;
    }

    /**
     * Removes first element
     */
    void pop_front() {
        auto temp = new Node<T>();
        temp = head;
        head = head->next;
        delete temp;
    }

    /**
     * Removes last element
     */
    void pop_back() {
        auto curr = new Node<T>();
        auto prev = new Node<T>();
        curr = head;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        prev->next = nullptr;
        delete curr;
    }
};


#endif //STUD_PAMSI_GRAPHS_LIST_H
