#include <iostream>
#include <AdjListGraph.h>
#include <AdjMatrixGraph.h>
#include "List.h"
#include <chrono>
#include <algorithm>


#define LOG(x) { std::cout << x << std::endl; }

template<typename T>
void sort_list(List<T> &list) {
    auto array = new T[list.size()];
    int cnt = 0;
    for (auto i: list) {
        array[cnt++] = i;
    }

    cnt = 0;


    std::sort(array, array + list.size());

    for (auto &i: list) {
        i = array[cnt];
        cnt++;
    }
    delete[] array;
}

int main() {

/*
    AdjListGraph graph(5);
    graph.insert_edge(0, 3, 10);
    graph.insert_edge(0, 1, 8);
    graph.insert_edge(0, 2, 7);
    graph.insert_edge(3, 4, 6);
     LOG(graph.get_edges())
 */

/*
    List<int> list;
    for (int i = 50; i >= 0; --i) {
        list.push_back(i);
    }
    auto start = std::chrono::steady_clock::now();
    sort_list(list);
    auto end = std::chrono::steady_clock::now();


    LOG(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count())
    LOG(list)
*/
    return 0;

}
