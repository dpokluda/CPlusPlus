#pragma once

#include <memory>

template<typename T>
class Node
{
private:
	T _data;

public:
	Node(const T& value) : _data(value), left(nullptr), right(nullptr) {}
	// Node(const Node& other)
	// {
	// 	_data = other.data();
	// 	left = std::make_shared<Node<T>>(other.left->data());
	// 	right = std::make_shared<Node<T>>(other.right->data());
	// }

	std::shared_ptr<Node<T>> left;
	std::shared_ptr<Node<T>> right;
	T data() const { return _data; }
};

