//
// Created by lukasz-lap on 02.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_LIST_H
#define STUD_PAMSI_GRAPHS_LIST_H

#include "Node.h"
#include "NodeIterator.h"


template<typename T>
/**
 * @brief Single linked list with tail
 * @tparam T type of data in list
 */
class List {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    std::size_t count;

public:

    List() : head(nullptr),
             tail(nullptr),
             count(0) {}


/**
 * @brief Returns counted nodes in the list
 * @return  nodes in list
 */
    std::size_t size() const {
        return count;
    }

/**
 * @brief Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
    bool is_empty() const {
        return count == 0;
    }

/**
 * @brief Gets data from the front of the list, allows editing
 * @return requested data
 */
    T &front() {
        if (head != nullptr) {
            return head->data;
        }
    }

/**
 * @brief Gets data from the back of the list, allows editing
 * @return requested data
 */
    T &back() {
        if (tail != nullptr) {
            return tail->data;
        }
    }
//-----------------------------------------
/**
 * @brief Gets data from the front of the list, do not allow editing
 * @return requested data
 */
    const T &front() const {
        if (head != nullptr) {
            return head->data;
        }
    }

/**
 * @brief Gets data from the back of the list, do not allow editing
 * @return requested data
 */
    const T &back() const {
        if (tail != nullptr) {
            return tail->data;
        }
    }


/**
 * @brief For ranged loops
 * @return head of the list
 */
    NodeIterator<T> begin() const {
        return NodeIterator<T>(head);
    }

/**
 * @brief For ranged loops
 * @return very end of the list which is nullptr
 */
    NodeIterator<T> end() const {
        return NodeIterator<T>(nullptr);;
    }

    /**
     * @brief Checks if node with given data is present in the list
     * @param data data which is supposed to be contained
     * @return true if it is present, false otherwise
     */
    bool is_present(T data) const {
        if (head == nullptr || tail == nullptr) {
            return false;
        }
        auto curr = head;

        if (tail->data == data) {
            return true;
        }

        while (curr != tail) {
            if (curr->data == data) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    /**
     * @brief Changes content of node with given data (first found)
     * @param old_data old data in node
     * @param new_data new data in node
     */
    void update(T old_data, T new_data) {
        auto curr = head;

        if (tail->data == old_data) {
            tail->data = new_data;
        }

        while (curr != tail) {
            if (curr->data == old_data) {
                curr->data = new_data;
            }
            curr = curr->next;
        }
    }

/**
 * @brief Adds element at the front
 * @param data data to be inserted
 */
    void push_front(const T &data) {
        auto temp = std::make_shared<Node<T>>
                (data, head);
        head = temp;
        ++count;
    }

    /**
     * @brief Adds data at the back
     * @param data data to be inserted
     */
    void push_back(const T &data) {
        auto temp = std::make_shared<Node<T>>
                (data, nullptr);
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
     * @brief Allows to add data before node with given data (first one with given data)
     * @param prev_data data contained in prev_data node
     * @param new_data data which is to be contained in new node
     */
    void push_after(const T &prev_data, const T &new_data) {

        auto curr = head;

        while (curr != tail && curr->data != prev_data) {
            curr = curr->next;
        }


        auto new_node = std::make_shared<Node<T>>
                (new_data, curr->next);
        curr->next = new_node;
        ++count;
    }

/**
 *@brief Removes first element
 */
    void pop_front() {
        if (head == nullptr)
            return;
        auto curr = head;
        head = head->next;

        curr.reset();
        --count;
    }

/**
 * @brief Removes last element
 */
    void pop_back() {
        if (head == nullptr) {
            return;
        }


        if (head->next == nullptr) {
            head.reset();
            --count;
            return;
        }


        auto curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        tail = curr;
        (curr->next).reset();


        curr->next = nullptr;
        --count;

    }

    /**
     * @brief removes node with selected data
     * @param data_selected node containing that data will be removed
     */
    void pop_selected(const T &data_selected) {
        if (head->data == data_selected) {
            pop_front();
            return;
        }
        if (tail->data == data_selected) {
            pop_back();
            return;
        }

        auto curr = head;

        while (curr->next->data != data_selected) {
            curr = curr->next;
            if (curr == tail) {
                return;
            }
        }


        auto temp = curr->next;
        curr->next = temp->next;
        temp.reset();
        --count;


    }

    /**
     * @brief Returns content of node at given index (from 0)
     * @param index index of node
     * @return data stored in node at index
     */
    T at(std::size_t index) const {
        if (index < count) {


            auto curr = head;


            std::size_t i = 0;
            while (curr != nullptr) {
                if (i == index)
                    return (curr->data);
                i++;
                curr = curr->next;
            }
        }
    }

    /**
     * @brief Removes element at given index(from 0)
     * @param index node at that index will be deleted
     */
    void pop_at(std::size_t index) {

        if (head == nullptr) {
            return;
        }


        auto curr = head;

        if (index == 0) {
            head = head->next;
            curr.reset();
            --count;
            return;
        }


        for (int i = 0; curr != nullptr && i < index - 1; ++i) {
            curr = curr->next;
        }


        if (curr == nullptr || curr->next == nullptr) {
            return;
        }


        auto next = curr->next->next;
        curr->next.reset();

        curr->next = next;
        --count;
    }

    /**
     * @brief Display list
     */
    friend std::ostream &operator<<(std::ostream &os, const List<T> &obj) {

        for (const auto &i: obj) {
            os << i << " ";
        }

        return os;
    }

};


#endif //STUD_PAMSI_GRAPHS_LIST_H
