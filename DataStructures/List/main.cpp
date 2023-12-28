#include <iostream>
#include "list.h"

int main() {
    List<int> list = { 1, 2, 3, 4 };

    list.PushBack(5);
    list.PushBack(10);
    list.PushBack(15);

    std::cout << "List size: " << list.GetSize() << std::endl;
    for (unsigned long i = 0; i < list.GetSize(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    list.PopBack();
    list.PushBack(20);

    std::cout << "Modified list: ";
    for (unsigned long i = 0; i < list.GetSize(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
