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
#include "ResultToFileSaver.h"
#include <stdexcept>

class UserInterface {
private:
    GraphBuilder builder;
    std::unique_ptr<Graph> graph;
    ResultToFileSaver saver;
    int instances;          //number of graph instances to be generated
    int source_vertex = 0;  //starting vertex for Bellman-Ford algorithm
    double *time;           //array of measured algorithm time
    bool write_result;      //write result to file?


    bool Parse(int argc, char **argv);

    GraphType RecogniseType(const std::string &option) const;

    void PerformDemo();

public:
    void Begin(int argc, char **argv);

    UserInterface();

    ~UserInterface();
};


#endif //STUD_PAMSI_GRAPHS_USERINTERFACE_H
