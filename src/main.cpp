#include <iostream>
#include "List.h"
#include "NodeIterator.h"

int main() {
    List<int> list;
    list.push_back(12);
    list.push_back(89);
    list.push_back(52);
    list.push_back(77);
    list.push_back(125);
    list.push_back(777);

    list.pop_back();
    list.pop_back();

    list.push_back(99);
    list.push_back(999);

    list.pop_back();
    std::cout << list;

    return 0;

}
