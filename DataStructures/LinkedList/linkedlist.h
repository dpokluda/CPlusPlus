#pragma once

#include <memory>
#include <iostream>

template<typename T>
class LinkedList
{
private:
	struct Node
	{
		T _data;
		std::unique_ptr<Node> _next;

		Node(T value) : _data(value), _next(nullptr) {}
	};

	std::unique_ptr<Node> _head;

public:
	// constructors
	LinkedList() : _head(nullptr) {}
	LinkedList(std::initializer_list<T> list) : LinkedList()
	{
		for (auto value : list)
		{
			PushBack(value);
		}
	}

	void PushBack(const T& value)
	{
		auto newTail = std::make_unique<Node>(value);
		if (!_head)
		{
			_head = std::move(newTail);
			return;
		}

		auto current = _head.get();
		while (current->_next)
		{
			current = current->_next.get();
		}
		current->_next = std::move(newTail);
	}

	void PushFront(const T& value)
	{
		auto newHead = std::make_unique<Node>(value);
		if (_head)
		{
			newHead->_next = std::move(_head);
		}
		_head = std::move(newHead);
	}

	T PopBack()
	{
		if (!_head) return false;

		T data;
		if (!_head->_next)
		{
			data = _head->_data;
			_head.reset();
		}
		else
		{
			auto current = _head.get();
			while (current->_next->_next)
			{
				current = current->_next.get();
			}
			data = current->_next->_data;
			current->_next.reset();
		}

		return data;
	}

	T PopFront()
	{
		if (!_head) return false;

		auto data = _head->_data;
		_head = std::move(_head->_next);

		return data;
	}

	bool Remove(const T& value)
	{
		if (!_head) return false;

		if (_head->_data == value)
		{
			_head = std::move(_head->_next);
			return true;
		}

		auto current = _head.get();
		while (current->_next && current->_next->_data != value)
		{
			current = current->_next.get();
		}

		if (current->_next->_data == value)
		{
			current->_next = std::move(current->_next->_next);
			return true;
		}

		return false;
	}

	void Print() const
	{
		auto current = _head.get();
		while (current)
		{
			std::cout << current->_data << " -> ";
			current = current->_next.get();
		}
		std::cout << "nullptr\n";
	}
};
