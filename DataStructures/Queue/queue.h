#pragma once

template<typename T>
class Queue
{
private:
	std::unique_ptr<T[]> _data;
	unsigned long _capacity;
	unsigned long _head; // where the dequeue from
	unsigned long _tail; // next available index for newly enqueued items

public:
	Queue() : _data(nullptr), _capacity(0), _head(0), _tail(0) {}

	bool IsEmpty() const
	{
		return _head == _tail;
	}

	unsigned long GetSize() const
	{
		return _tail - _head;
	}

	void Enqueue(const T& value)
	{
		if (_tail == _capacity)
		{
			unsigned long newCapacity = _capacity;
			if (_capacity == 0)
			{
				newCapacity = 1;
			}
			else if (_tail - _head >= _capacity / 2)
			{
				newCapacity *= 2;
			}
			Resize(newCapacity);
		}
		_data[_tail++] = value;
	}

	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Queue is empty");
		}

		return _data[_head++];
	}

	T Peek() const
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Queue is empty");
		}

		return _data[_head];
	}

private:
	void Resize(unsigned long newCapacity)
	{
		std::unique_ptr<T[]> newData(new T[newCapacity]);
		for(unsigned long i = _head; i < _tail; i++)
		{
			newData[i - _head] = _data[i];
		}

		_data = std::move(newData);
		_capacity = newCapacity;
		_tail = _tail - _head;
		_head = 0;
	}
};

