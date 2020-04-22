//
// Created by lukasz-lap on 22.04.2020.
//

#ifndef STUD_PAMSI_GRAPHS_GRAPHFILEMANAGER_H
#define STUD_PAMSI_GRAPHS_GRAPHFILEMANAGER_H

#include <string>

class GraphFileManager {
private:
    std::string write_filename;
    std::string read_filename;
public:

    void SetWriteFilename(std::string filename);

    void SetReadFilename(std::string filename);

    void Write();


};


#endif //STUD_PAMSI_GRAPHS_GRAPHFILEMANAGER_H
