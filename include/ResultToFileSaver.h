//
// Created by lukasz-lap on 26.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_RESULTTOFILESAVER_H
#define STUD_PAMSI_GRAPHS_RESULTTOFILESAVER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


class ResultToFileSaver {
private:


    std::string main_dir;
    std::string filename;
    std::string extenstion;

    std::ostringstream full_path;

    std::size_t size;
    std::string type;
    double density;
    int instances;

public:


    void setSize(size_t size);

    void setType(const std::string &type);

    void setDensity(double density);

    void setInstances(int instances);


    void SaveToFile(double *time);

    ResultToFileSaver();

    ~ResultToFileSaver() = default;
};


#endif //STUD_PAMSI_GRAPHS_RESULTTOFILESAVER_H
