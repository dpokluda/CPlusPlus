#pragma once

#include <memory>
#include <iostream>
#include <queue>

template <typename T>
struct TreeNode
{
	T value;
	std::unique_ptr<TreeNode<T>> left;
	std::unique_ptr<TreeNode<T>> right;

	TreeNode(T val) : value(val), left(nullptr), right(nullptr)
	{
	}
};

template <typename T>
class BinaryTree
{
private:
	std::unique_ptr<TreeNode<T>> root;

public:
	BinaryTree() : root(nullptr)
	{
	}

	void Insert(const T& value)
	{
		root = InsertRecursively(root, value);
	}

	void Print() const
	{
		InorderTraversalRecursively(root.get());
		std::cout << std::endl;
	}

	void PrintTree() const
	{
		PrintTree(root.get());
		std::cout << std::endl;
	}

private:
	std::unique_ptr<TreeNode<T>> InsertRecursively(std::unique_ptr<TreeNode<T>>& current, const T& value)
	{
		if (!current)
		{
			return std::make_unique<TreeNode<T>>(value);
		}

		if (value < current->value)
		{
			current->left = InsertRecursively(current->left, value);
		}
		else if (value > current->value)
		{
			current->right = InsertRecursively(current->right, value);
		}

		return std::move(current);
	}

	void InorderTraversalRecursively(const TreeNode<T>* node) const
	{
		if (!node) return;

		InorderTraversalRecursively(node->left.get());
		std::cout << node->value << " ";
		InorderTraversalRecursively(node->right.get());
	}

	void PrintTree(const TreeNode<T>* root) const
	{
		auto currentLevel = std::make_unique<std::queue<const TreeNode<T>*>>();
		auto nextLevel = std::make_unique<std::queue<const TreeNode<T>*>>();

		currentLevel->push(root);
		while (!currentLevel->empty() || !nextLevel->empty())
		{
			if (currentLevel->empty())
			{
				currentLevel = std::move(nextLevel);
				nextLevel = std::make_unique<std::queue<const TreeNode<T>*>>();
				std::cout << '\n';
			}

			const auto node = currentLevel->front();
			std::cout << node->value << " ";

			if (node->left)
			{
				nextLevel->push(node->left.get());
			}
			if (node->right)
			{
				nextLevel->push(node->right.get());
			}
			currentLevel->pop();
		}
	}
};
