#include <chrono>
#include <algorithm>
#include <UserInterface.h>



#define LOG(x) { std::cout << std::boolalpha<< x << std::endl; }



int main(int argc, char **argv) {

    srand(time(NULL));
    UserInterface ui;
    ui.Begin(argc, argv);

    return 0;

}
