//
// Created by lukasz-lap on 26.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_RESULTTOFILESAVER_H
#define STUD_PAMSI_GRAPHS_RESULTTOFILESAVER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "List.h"


class ResultToFileSaver {
private:
    typedef std::pair<int32_t, List<std::size_t>> Pair;

    std::string main_time_dir;
    std::string main_algorithm_dir;




    std::size_t size;
    std::string type;
    double density;
    int instances;

public:


    void setSize(size_t size);

    void setType(const std::string &type);

    void setDensity(double density);

    void setInstances(int instances);

    void SaveAlgorithmResults(std::unique_ptr<Pair[]> &result);

    void SaveTime(double *time);

    ResultToFileSaver();

    ~ResultToFileSaver() = default;
};


#endif //STUD_PAMSI_GRAPHS_RESULTTOFILESAVER_H
