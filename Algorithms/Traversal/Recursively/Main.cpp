#include <iostream>
#include <memory>
#include <queue>

#include "Node.h"

void PreOrder(const Node<int>& root)
{
    std::cout << root.data() << " ";

    if (root.left != nullptr)
    {
        PreOrder(*root.left);
    }

    if (root.right != nullptr)
    {
        PreOrder(*root.right);
    }
}

void InOrder(const Node<int>& root)
{
    if (root.left != nullptr)
    {
        InOrder(*root.left);
    }

    std::cout << root.data() << " ";

    if (root.right != nullptr)
    {
        InOrder(*root.right);
    }
}

void PostOrder(const Node<int>& root)
{
    if (root.left != nullptr)
    {
        PostOrder(*root.left);
    }

    if (root.right != nullptr)
    {
        PostOrder(*root.right);
    }

    std::cout << root.data() << " ";

}

void LevelOrder(const Node<int>& root)
{
    std::queue<std::shared_ptr<Node<int>>> nodes;
    nodes.push(std::make_shared<Node<int>>(root));

    while (!nodes.empty())
    {
        const auto node = nodes.front();
        nodes.push(node->left);
        nodes.push(node->right);
        std::cout << node->data() << " ";
        nodes.pop();
    }
}

int main()
{
    Node<int> root{ 1 };
    root.left = std::make_shared<Node<int>>(2);
    root.right = std::make_shared<Node<int>>(3);
    root.left->left = std::make_shared<Node<int>>(4);
    root.left->right = std::make_shared<Node<int>>(5);

    std::cout << "Pre-order:\n";
    PreOrder(root);

    std::cout << "\n\nIn-order:\n";
    InOrder(root);

    std::cout << "\n\nPost-order:\n";
    PostOrder(root);

    std::cout << "\n\nLevel-order:\n";
    LevelOrder(root);
}
