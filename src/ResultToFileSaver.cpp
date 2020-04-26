//
// Created by lukasz-lap on 26.04.2020.
//

#include "ResultToFileSaver.h"

ResultToFileSaver::ResultToFileSaver() {
    extenstion = ".csv";
    main_dir = "results/";
    filename = "res";
}

void ResultToFileSaver::SaveToFile(double *time) {
    std::ofstream stream;
    full_path << "/" << main_dir << "/" << size << "/" << filename << extenstion;

    stream.open(full_path.str(), std::ios::out | std::ios::app);
    if (stream.fail()) {
        std::cout << "Failed to open file!" << std::endl;
        return;
    }
    std::ostringstream header;
    header << type << "_" << density;

    stream << ",";
    stream << header.str();
    for (int i = 0; i < instances; ++i) {
        stream << time[i] << std::endl;
    }

    stream.flush();
    stream.close();
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
