#include <iostream>
#include <memory>
#include <queue>
#include <stack>

#include "Node.h"

std::vector<int> InOrder(const std::shared_ptr<Node<int>>& root)
{
    std::vector<int> items;
    std::stack<std::shared_ptr<Node<int>>> nodes;
    auto current = root;

    while (current != nullptr || !nodes.empty())
    {
        while (current != nullptr)
        {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();
        nodes.pop();

        items.push_back(current->data());

        current = current->right;
    }

    return items;
}

std::vector<int> LevelOrder(const std::shared_ptr<Node<int>>& root)
{
    std::vector<int> items;
    std::queue<std::shared_ptr<Node<int>>> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
	    const auto node = nodes.front();
        if (node->left != nullptr)
        {
            nodes.push(node->left);
        }
        if (node->right != nullptr)
        {
            nodes.push(node->right);
        }
        items.push_back(node->data());
        nodes.pop();
    }

    return items;
}

int main()
{
	const std::shared_ptr<Node<int>> root = std::make_shared<Node<int>>(1);
    root->left = std::make_shared<Node<int>>(2);
    root->right = std::make_shared<Node<int>>(3);
    root->left->left = std::make_shared<Node<int>>(4);
    root->left->right = std::make_shared<Node<int>>(5);

    std::cout << "\n\nIn-order:\n";
    auto items = InOrder(root);
    for (const int item : items)
    {
        std::cout << item << " ";
    }

    std::cout << "\n\nLevel-order:\n";
    items = LevelOrder(root);
    for (const int item : items)
    {
        std::cout << item << " ";
    }
}
