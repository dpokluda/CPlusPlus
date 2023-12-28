#include <iostream>

#include "queue.h"

int main() {
    Queue<int> queue;

    if (queue.IsEmpty())
		std::cout << "Queue is empty." << std::endl;

    queue.Enqueue(5);
    queue.Enqueue(10);
    queue.Enqueue(15);

    std::cout << "Front of the queue: " << queue.Peek() << std::endl;
    std::cout << "Queue size: " << queue.GetSize() << std::endl;

    auto value = queue.Dequeue();
    std::cout << "Dequeued value: " << value << std::endl;
    queue.Enqueue(20);
    std::cout << "Enqueued value: 20" << std::endl;

    std::cout << "After modifications, front of the queue: " << queue.Peek() << std::endl;

    return 0;
}
