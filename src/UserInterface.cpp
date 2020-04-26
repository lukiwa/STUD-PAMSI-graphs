//
// Created by lukasz-lap on 25.04.2020.
//


//#include <UtilityAlgorithms.h>
#include "UserInterface.h"

#define LOG(x) { std::cout << x << std::endl; }

void UserInterface::Begin(int argc, char **argv) {

    if (!Parse(argc, argv)) {
        return;
    }
    graph = builder.Build();


    auto start = std::chrono::steady_clock::now();
  //  utility::BellmanFord(*graph, 0);
    auto end = std::chrono::steady_clock::now();
    LOG(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count())

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
            ("write,w", po::value<std::string>(), "Shortest path result path")
            ("read,r", po::value<std::string>(), "Read graph from file")
            ("type,t", po::value<std::string>(), "Graph type - [LIST, MATRIX]")
            ("size,s", po::value<std::size_t>(), "Number of graph vertices")
            ("density,d", po::value<double>(), "Graph density (eg. 0.5 = 50%)");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(description).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
        LOG(description)
        return false;
    }
    if (vm.count("xdemo")) {
        //TODO
        LOG("demo")
        return false;
    }

    if (vm.count("type")) {
        std::string option = vm["type"].as<std::string>();

        if (option == "LIST") {
            builder.SetType(GraphType::LIST);
            LOG(option)
        } else if (option == "MATRIX") {
            builder.SetType(GraphType::MATRIX);
            LOG(option)
        } else {
            LOG(description)
        }
    }
    if (vm.count("size")) {
        builder.SetSize(vm["size"].as<std::size_t>());
        LOG(vm["size"].as<std::size_t>());

    }
    if (vm.count("density")) {
        builder.SetDensity(vm["density"].as<double>());
        LOG(vm["density"].as<double>())
    }
    return true;
}
