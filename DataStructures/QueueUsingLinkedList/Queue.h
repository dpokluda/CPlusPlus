#pragma once

#include "LinkedList.h"

template<typename T>
class Queue
{
private:
	std::unique_ptr<LinkedList<T>> _list;

public:
	Queue()
	{
		_list = std::make_unique<LinkedList<T>>();
	}

	bool IsEmpty() const
	{
		return _list->IsEmpty();
	}

	void Enqueue(const T& value)
	{
		_list->PushBack(value);
	}

	T Dequeue()
	{
		return _list->PopFront();
	}

	T Peek() const
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Queue is empty");
		}

		return _list->PeekFront();
	}
};

