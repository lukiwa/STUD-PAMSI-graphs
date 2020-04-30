//
// Created by lukasz-lap on 26.04.2020.
//

#include <iomanip>
#include "ResultToFileSaver.h"

ResultToFileSaver::ResultToFileSaver() {
    main_time_dir = "results";
    main_algorithm_dir = "algorithm_results";

}


/**
 * @brief Save results to file, which params has been set
 * @param time
 */
void ResultToFileSaver::SaveTime(double *time) {
    std::ofstream stream;
    std::ostringstream filename;
    std::ostringstream full_path;


    filename << type << "_" << density;
    full_path << main_time_dir << "/" << size << "/" << filename.str() << ".csv";


    stream.open(full_path.str(), std::ios::out | std::ios::app);
    if (stream.fail()) {
        std::cout << "Failed to open file!" << std::endl;
        return;
    }

    for (int i = 0; i < instances; ++i) {
        stream << std::fixed << std::setprecision(0) << time[i] << std::endl;
    }

    stream.flush();
    stream.close();
}


void ResultToFileSaver::SaveAlgorithmResults(std::unique_ptr<Pair[]> &result) {
    static int curr_instance = 1;
    std::ofstream stream;
    std::ostringstream filename;
    std::ostringstream full_path;

    filename << type << "_" << size << "_" << density;
    full_path << main_algorithm_dir << "/" << filename.str();


    stream.open(full_path.str(), std::ios::out | std::ios::app);
    if (stream.fail()) {
        std::cout << "Failed to open file!" << std::endl;
        return;
    }
    //space between instances + enumeration
    stream << "Graph instance number : " << curr_instance << std::endl;
    for (std::size_t i = 0; i < this->size; ++i) {
        stream << i << "  " << result[i].first << "  " << result[i].second << std::endl;
    }
    stream << std::endl << std::endl;
    ++curr_instance;
}

void ResultToFileSaver::setSize(size_t size) {
    ResultToFileSaver::size = size;
}

void ResultToFileSaver::setType(const std::string &type) {
    ResultToFileSaver::type = type;
}

void ResultToFileSaver::setDensity(double density) {
    ResultToFileSaver::density = density;
}

void ResultToFileSaver::setInstances(int instances) {
    ResultToFileSaver::instances = instances;
}



