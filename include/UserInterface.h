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

class UserInterface {
private:
    GraphBuilder builder;
    std::unique_ptr<Graph> graph;
    ResultToFileSaver saver;
    int instances;
    double *time;
    bool write_result;



    bool Parse(int argc, char **argv);

public:
    void Begin(int argc, char **argv);

    UserInterface();

    ~UserInterface();
};


#endif //STUD_PAMSI_GRAPHS_USERINTERFACE_H
