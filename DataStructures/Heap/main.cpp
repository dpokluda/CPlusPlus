#include <iostream>
#include "heap.h"

int main() {
    Heap heap;

    heap.insert(3);
    heap.insert(5);
    heap.insert(1);
    heap.insert(10);

    std::cout << "Extracted from max-heap: ";
    while (!heap.isEmpty()) {
        std::cout << heap.extractMax() << " ";
    }
    std::cout << std::endl;

    return 0;
}
