#include <iostream>
#include "list.h"

int main() {
    List<int> list = {1, 2, 3, 4};

    list.push_back(5);
    list.push_back(10);
    list.push_back(15);

    std::cout << "List size: " << list.size() << std::endl;
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    list.pop_back();
    list.push_back(20);

    std::cout << "Modified list: ";
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
