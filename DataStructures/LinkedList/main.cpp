#include <iostream>

#include "LinkedList.h"

int main() {
    LinkedList list = { 1, 2, 3 };
    list.PushBack(5);
    list.PushBack(10);
    list.PushBack(15);

    std::cout << "Initial list: ";
    list.Print();

    list.PushFront(0);

    std::cout << "After adding 0 to the front: ";
    list.Print();

    list.Remove(10);

    std::cout << "After removing 10: ";
    list.Print();

    std::cout << "Removing first element: " << list.PopFront() << "\n";
    std::cout << "Removing last element: " << list.PopBack() << "\n";
    std::cout << "Final queue:\n";
    list.Print();

    return 0;
}
