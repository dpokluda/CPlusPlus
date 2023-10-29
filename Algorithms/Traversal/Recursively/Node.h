#pragma once

#include <memory>

template<typename T>
class Node
{
private:
	T _data;

public:
	Node(const T& value) : _data(value), left(nullptr), right(nullptr) {}

	std::shared_ptr<Node<T>> left;
	std::shared_ptr<Node<T>> right;
	T data() const { return _data; }
};

