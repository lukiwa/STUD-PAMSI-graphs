//
// Created by lukasz-lap on 25.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_USERINTERFACE_H
#define STUD_PAMSI_GRAPHS_USERINTERFACE_H

#include <exception>
#include <iostream>
#include <boost/program_options.hpp>
#include "GraphBuilder.h"
#include <memory>
#include <chrono>


class UserInterface {
private:
    GraphBuilder builder;
    std::unique_ptr<Graph> graph;

    /*TODO
    std::string algorithm_name;
    int number_of_arrays;
    std::size_t size;
    double already_sorted;
    std::string already_sorted_way;
    SortingAlgorithm sorting_algorithm;
    double sorting_time;
    ManageSorting<int> sort;
    ToFileSaver save;
    std::tuple<std::size_t, std::unique_ptr<int[]>> array_with_size;
    TestArrayGenerator generator;
*/


    bool Parse(int argc, char **argv);

public:
    void Begin(int argc, char **argv);

    UserInterface() = default;

    ~UserInterface() = default;
};


#endif //STUD_PAMSI_GRAPHS_USERINTERFACE_H
