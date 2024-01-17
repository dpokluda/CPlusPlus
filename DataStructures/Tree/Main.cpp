#include <iostream>

#include "Tree.h"

int main()
{
    std::cout << "BALANCED:\n";
    BinaryTree<int> tree;
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(1);
    tree.Insert(4);
    tree.Insert(7);
    tree.Insert(9);

    std::cout << "Inorder traversal: ";
    tree.Print();  // Expected: 1 3 4 5 7 8 9

    std::cout << "Tree:\n";
    tree.PrintTree();

    std::cout << "UNBALANCED:\n";
    BinaryTree<int> unbalanced;
    for (int i = 9; i > 0; i--)
    {
        unbalanced.Insert(i);
    }
    tree.Print(); // Expected: 1 3 4 5 7 8 9

    std::cout << "Tree:\n";
    tree.PrintTree();
}
