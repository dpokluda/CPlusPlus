#pragma once

#include <memory>
#include <stdexcept>

template<typename T>
class Stack
{
private:
	std::unique_ptr<T[]> _data;
	unsigned int _capacity;
	unsigned int _top_index;

public:
	Stack() : _data(nullptr), _capacity(0), _top_index(0) {}

	bool IsEmpty() const
	{
		return _top_index == 0;
	}

	unsigned int GetSize() const
	{
		return _top_index;
	}

	void Push(const T& value)
	{
		if (_top_index == _capacity)
		{
			Resize(_capacity == 0 ? 1 : _capacity * 2);
		}

		_data[_top_index++] = value;
	}

	T Pop()
	{
		if (_top_index == 0)
		{
			throw std::out_of_range("Stack is empty");
		}

		return _data[--_top_index];
	}

	T Peek() const
	{
		if (_top_index == 0)
		{
			throw std::out_of_range("Stack is empty");
		}

		return _data[_top_index - 1];
	}

private:
	void Resize(unsigned int newCapacity)
	{
		std::unique_ptr<T[]> newData(new T[newCapacity]);
		for (unsigned int i = 0; i < _top_index; i++)
		{
			newData[i] = std::move(_data[i]);
		}

		_data = std::move(newData);
		_capacity = newCapacity;
	}
};

