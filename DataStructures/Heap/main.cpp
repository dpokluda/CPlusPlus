#include <iostream>
#include "heap.h"

int main()
{
    Heap<int> heap;
    if (heap.IsEmpty())
        std::cout << "Heap is empty.";

    heap.Enqueue(3);
    heap.Enqueue(1);
    heap.Enqueue(5);
    heap.Enqueue(10);
    heap.Enqueue(2);
    heap.Enqueue(4);

    std::cout << "After populating the heap, the heap content is:\n";
    heap.Print();

    auto max = heap.Dequeue();
    std::cout << "\nMax value: " << max << "\n";
    heap.Print();

    max = heap.Dequeue();
    std::cout << "\nMax value: " << max << "\n";
    heap.Print();
}
