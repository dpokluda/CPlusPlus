#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    list.append(5);
    list.append(10);
    list.append(15);

    std::cout << "Initial list: ";
    list.print();

    list.pushFront(1);

    std::cout << "After adding 1 to the front: ";
    list.print();

    list.remove(10);

    std::cout << "After removing 10: ";
    list.print();

    return 0;
}
