#include <iostream>
#include <memory>
#include <stdexcept>
#include "queue.h"

int main() {
    Queue<int> queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);

    std::cout << "Front of the queue: " << queue.front() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    queue.dequeue();
    queue.enqueue(20);

    std::cout << "After modifications, front of the queue: " << queue.front() << std::endl;

    return 0;
}
