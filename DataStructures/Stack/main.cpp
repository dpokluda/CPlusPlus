#include <iostream>
#include "stack.h"

int main() {
    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "Top of the stack: " << stack.peek() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;

    auto value = stack.pop();
    std::cout << "Popped value: " << value << std::endl;
    stack.push(20);
    std::cout << "Pushed value: " << 20 << std::endl;

    std::cout << "After modifications, top of the stack: " << stack.peek() << std::endl;

    return 0;
}
