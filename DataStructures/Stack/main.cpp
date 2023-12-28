#include <iostream>

#include "stack.h"

int main() {
    Stack<int> stack;

    std::cout << "Stack is empty: " << stack.IsEmpty() << std::endl;

    stack.Push(5);
    stack.Push(10);
    stack.Push(15);

    std::cout << "Top of the stack: " << stack.Peek() << std::endl;
    std::cout << "Size of the stack: " << stack.GetSize() << std::endl;

    const auto value = stack.Pop();
    std::cout << "Popped value: " << value << std::endl;
    stack.Push(20);
    std::cout << "Pushed value: " << 20 << std::endl;

    std::cout << "After modifications, top of the stack: " << stack.Peek() << std::endl;

    return 0;
}
