//
// Created by lukasz-lap on 25.04.2020.
//


#include <UtilityAlgorithms.h>
#include "UserInterface.h"

#define LOG(x) { std::cout << x << std::endl; }

/**
 * @brief Begin working on parsing, generating graph,
 *        performing bellman ford, and measuring time
 */
void UserInterface::Begin(int argc, char **argv) {

    if (!Parse(argc, argv)) {
        return;
    }
    for (int i = 0; i < instances; ++i) {
        graph = builder.Build();
        auto start = std::chrono::steady_clock::now();
        auto res = utility::BellmanFord(*graph, 0);
        auto end = std::chrono::steady_clock::now();
        time[i] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        if (write_result) { saver.SaveAlgorithmResults(res); }
    }
    saver.SaveTime(time);


}

/**
 * @brief parses command line options
 * @param argc
 * @param argv
 * @return true if parsed, false if displaying help or demo
 */
bool UserInterface::Parse(int argc, char **argv) {
    namespace po = boost::program_options;

    po::options_description description("Help");
    description.add_options()
            ("help",
             "If user want to read graph from file should only specify read path, optionally result path")
            ("xdemo", "Perform demo of graph methods")
            ("write,w", "Write shortest path to file")
            ("read,r", po::value<std::string>(), "Read graph from file")
            ("type,t", po::value<std::string>(), "Graph type - [LIST, MATRIX]")
            ("size,s", po::value<std::size_t>(), "Number of graph vertices")
            ("density,d", po::value<double>(), "Graph density (eg. 0.5 = 50%)")
            ("instances,i", po::value<std::size_t>(), "Number of graph instances to be tested");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(description).run(), vm);
    po::notify(vm);


    if (vm.count("help") || argc == 1) {
        LOG(description)
        return false;
    }
    if (vm.count("xdemo")) {
        //TODO
        LOG("demo")
        return false;
    }
    if (vm.count("write")) {
        write_result = true;
    }

    if (vm.count("type")) {
        std::string option = vm["type"].as<std::string>();

        if (option == "LIST") {
            builder.SetType(GraphType::LIST);
            saver.setType(option);
            LOG(option)
        } else if (option == "MATRIX") {
            builder.SetType(GraphType::MATRIX);
            saver.setType(option);
            LOG(option)
        } else {
            LOG(description)
        }
    }
    if (vm.count("size")) {
        std::size_t size = vm["size"].as<std::size_t>();
        builder.SetSize(size);
        saver.setSize(size);
        LOG(size);
    }
    if (vm.count("density")) {
        double density = vm["density"].as<double>();
        builder.SetDensity(density);
        saver.setDensity(density);
        LOG(density)
    }

    if (vm.count("instances")) {
        this->instances = vm["instances"].as<std::size_t>();
        saver.setInstances(instances);
        this->time = new double[instances];
        LOG(instances);
    }
    return true;
}

UserInterface::UserInterface() {
    this->time = nullptr;
    write_result = false;
}

UserInterface::~UserInterface() {
    delete[] time;
}
