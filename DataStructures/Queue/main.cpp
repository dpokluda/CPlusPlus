#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);

    std::cout << "Front of the queue: " << queue.front() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    auto value = queue.dequeue();
    std::cout << "Dequeued value: " << value << std::endl;
    queue.enqueue(20);
    std::cout << "Enqueued value: 20" << std::endl;

    std::cout << "After modifications, front of the queue: " << queue.front() << std::endl;

    return 0;
}
