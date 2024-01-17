#pragma once

#include <memory>
#include <iostream>
#include <queue>

template <typename T>
struct TreeNode
{
	T value;
	int height;
	std::shared_ptr<TreeNode<T>> left;
	std::shared_ptr<TreeNode<T>> right;

	TreeNode(T val) : value(val), height(1), left(nullptr), right(nullptr)
	{
	}
};

template <typename T>
class BinaryTree
{
private:
	std::shared_ptr<TreeNode<T>> root;

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
	std::shared_ptr<TreeNode<T>> InsertRecursively(std::shared_ptr<TreeNode<T>>& current, const T& value)
	{
		if (!current)
		{
			return std::make_shared<TreeNode<T>>(value);
		}

		if (value < current->value)
		{
			current->left = InsertRecursively(current->left, value);
		}
		else if (value > current->value)
		{
			current->right = InsertRecursively(current->right, value);
		}

		UpdateHeight(current);
		return Balance(current);
	}

	// Update the height of a node
	void UpdateHeight(std::shared_ptr<TreeNode<T>>& node)
	{
		node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
	}

	// Get the height of a node
	int GetHeight(std::shared_ptr<TreeNode<T>>& node)
	{
		if (!node) return 0;
		return node->height;
	}

	// Get the balance factor of a node
	// > 1: Left heavy
	// < -1: Right heavy
	int GetBalanceFactor(std::shared_ptr<TreeNode<T>>& node)
	{
		if (!node) return 0;
		return GetHeight(node->left) - GetHeight(node->right);
	}


	// Balance the node
	std::shared_ptr<TreeNode<T>> Balance(std::shared_ptr<TreeNode<T>>& node)
	{
		const int balanceFactor = GetBalanceFactor(node);

		// Left heavy
		if (balanceFactor > 1)
		{
			// Left-right heavy
			if (GetBalanceFactor(node->left) < 0)
			{
				node->left = LeftRotate(node->left);
			}
			return RightRotate(node);
		}

		// Right heavy
		if (balanceFactor < -1)
		{
			// Right-left heavy
			if (GetBalanceFactor(node->right) > 0)
			{
				node->right = RightRotate(node->right);
			}
			return LeftRotate(node);
		}

		return node;
	}

	std::shared_ptr<TreeNode<T>> RightRotate(std::shared_ptr<TreeNode<T>>& y)
	{
		auto x = y->left;
		auto T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;

		// Update heights
		UpdateHeight(y);
		UpdateHeight(x);

		// Return new root
		return x;
	}

	std::shared_ptr<TreeNode<T>> LeftRotate(std::shared_ptr<TreeNode<T>>& x)
	{
		auto y = x->right;
		auto T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		// Update heights
		UpdateHeight(x);
		UpdateHeight(y);

		// Return new root
		return y;
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
