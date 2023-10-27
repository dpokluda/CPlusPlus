#pragma once

#include <memory>
#include <stdexcept>

template<typename T>
class List
{
private:
	std::unique_ptr<T[]> _data;
	unsigned long _size;
	unsigned long _capacity;

public:
	List() : _data(nullptr), _size(0), _capacity(0) {}
	List(std::initializer_list<T> list) : List()
	{
		Resize(list.size());
		for (const auto& value : list)
		{
			PushBack(value);
		}
	}

	bool IsEmpty() const { return _size == 0; }

	unsigned long GetSize() const { return _size; }

	unsigned long GetCapacity() const { return _capacity; }

	void PushBack(const T& value)
	{
		if (_size == _capacity)
		{
			Resize(_capacity == 0 ? 1 : _capacity * 2);
		}

		_data[_size++] = value;
	}

	T& PopBack()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("List is empty");
		}

		return _data[--_size];
	}

	void Clear()
	{
		_data.reset();
		_size = 0;
		_capacity = 0;
	}

	T& operator[](unsigned long index)
	{
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}

		return _data[index];
	}

	const T& operator[](unsigned long index) const
	{
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}

		return _data[index];
	}

private:
	void Resize(unsigned long newCapacity)
	{
		if (newCapacity <= _size) return;

		std::unique_ptr<T[]> newData(new T[newCapacity]);
		for (unsigned long i = 0; i < _size; i++)
		{
			newData[i] = std::move(_data[i]);
		}

		_data = std::move(newData);
		_capacity = newCapacity;
	}
};
