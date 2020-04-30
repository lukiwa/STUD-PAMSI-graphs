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
        auto res = utility::BellmanFord(*graph, source_vertex);
        auto end = std::chrono::steady_clock::now();
        time[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        //checks whether user wants to save algorithm results to file
        if (write_result) { saver.SaveAlgorithmResults(res); }
    }
    saver.SaveTime(time);


}

/**
 * @brief parses command line options
 * @param argc
 * @param argv
 * @return true if parsed, false if displaying help or demo, failed parsing, read graph from file.
 */
bool UserInterface::Parse(int argc, char **argv) {
    namespace po = boost::program_options;

    po::options_description description("Help");
    description.add_options()
            ("help",
             "If user want to read graph from file should only specify read path, optionally result path")
            ("xdemo", "Perform demo of graph methods")
            ("write,w", "Write shortest path to file")
            ("read,r", po::value<std::string>(),
             "Read graph from file then terminates program (specify LIST or MATRIX)")
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
        PerformDemo();
        return false;
    }
    if (vm.count("write")) {
        write_result = true;
    }

    if (vm.count("type")) {
        std::string option = vm["type"].as<std::string>();
        try {
            auto type = RecogniseType(option);
            builder.SetType(type);
            saver.setType(option);
            LOG(option)
        } catch (std::exception &e) {
            LOG(e.what())
            LOG(description)
            return false;
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
    if (vm.count("read")) {
        std::string option = vm["read"].as<std::string>();
        try {
            auto type = RecogniseType(option);
            graph = utility::ReadGraphFromFile(type, source_vertex);
            LOG("Read, graph : ")
            graph->print();
            return false;
        } catch (std::exception &e) {
            LOG(e.what())
            LOG(description)
            return false;
        }

    }
}

UserInterface::UserInterface() {
    this->time = nullptr;
    write_result = false;
}

UserInterface::~UserInterface() {
    delete[] time;
}

/**
 * @brief Recognise graph type by string input
 * @return Graph type
 */
GraphType UserInterface::RecogniseType(const std::string &option) const {
    if (option == "LIST") {
        return GraphType::LIST;
    } else if (option == "MATRIX") {
        return GraphType::MATRIX;
    }
    throw std::invalid_argument("Graph type not recognised (must be MATRIX or LIST)!");
}

/**
 * @brief Perform demonstration of all graph methods
 */
void UserInterface::PerformDemo() {
    std::string s_type;
    GraphType type;
    LOG("Type of the graph (LIST or MATRIX): ")
    std::cin >> s_type;
    try {
        type = RecogniseType(s_type);
    } catch (std::exception &e) {
        LOG(e.what())
        return;
    }

    graph = utility::ReadGraphFromFile(type, source_vertex);
    LOG("Readed graph from file: ")
    graph->

            print();
    LOG(std::endl)


    LOG("Add edge {0 1 777} ")
    graph->insert_edge(0, 1, 777);
    graph->

            print();
    LOG(std::endl)

    LOG("Incident edges to 2 : ");
    LOG(graph->incident_edges(2))
    LOG(std::endl)

    LOG("Get edges : ")
    LOG(graph->get_edges());
    LOG(std::endl)

    LOG("Are adjacent id 5 and 2 (declared in file : ")
    LOG(graph->are_adjacent(5, 2))
    LOG(std::endl)

    LOG("Removing edge {5 2 92}: ")
    graph->
            remove_edge(GraphEdge(5, 2, 92)
    );
    graph->

            print();
    LOG(std::endl)

    LOG("Replacing {2 3 4} with weight 17")
    graph->
            replace(GraphEdge(2, 3, 4),
                    17);
    graph->

            print();
    LOG(std::endl)

    LOG("Inserting vertex with new data 12")
    graph->insert_vertex(12);
    LOG(graph->get_vertices())
    graph->

            print();
    LOG(std::endl)

    LOG("Replacing vertex data 12 with 14")
    graph->vertex_replace(12, 14);
    LOG(graph->get_vertices())
    LOG(std::endl)


    LOG("Removing vertex with id 1")
    graph->remove_vertex(1);
    graph->

            print();
    LOG(std::endl)

    LOG("Opposite vertex of 2 by edge {2 3 4}")
    LOG(graph->opposite(2, GraphEdge(2, 3, 4)));
    LOG(std::endl)

    LOG("End vertices of {2 3 4}")
    LOG(graph->end_vertices(GraphEdge(2, 3, 4)))
    LOG(std::endl)

    LOG("Adding edges - preparing for Bellman-Ford")
    graph->insert_edge(0, 1, 144);
    graph->insert_edge(1, 9, 101);
    graph->insert_edge(2, 4, 40);
    graph->insert_edge(4, 8, 102);
    graph->insert_edge(1, 3, 84);
    graph->insert_edge(0, 3, 37);
    graph->insert_edge(0, 5, 50);
    graph->insert_edge(5, 6, 11);
    graph->insert_edge(5, 7, 90);
    graph->

            print();
    LOG(std::endl)

    LOG("Starting Bellman from vertex : ")
    int source;
    std::cin >>
             source;
    auto res = utility::BellmanFord(*graph, source);
    LOG(std::endl)

    LOG("Results : ")
    for (
            std::size_t i = 0;
            i < graph->

                            get_vertices()

                    .

                            size();

            ++i) {
        std::cout << i << "  " << res[i].first << "  " << res[i].second <<
                  std::endl;
    }
}