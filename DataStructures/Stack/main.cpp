#include <iostream>
#include "stack.h"

int main() {
    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "Top of the stack: " << stack.top() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;

    stack.pop();
    stack.push(20);

    std::cout << "After modifications, top of the stack: " << stack.top() << std::endl;

    return 0;
}
