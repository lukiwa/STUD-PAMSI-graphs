#include <iostream>
#include "../include/List.h"

int main() {
    List<int> list;
    list.push_front(12);
    list.push_front(89);
    list.pop_back();
    list.pop_back();
   

    return 0;

}
