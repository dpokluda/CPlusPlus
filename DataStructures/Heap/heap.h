#pragma once

template<typename T>
class Heap
{
private:
	std::unique_ptr<T[]> _data;
	unsigned long _capacity;
	unsigned long _size;

public:
	Heap() : _capacity(0), _size(0)
	{}

	bool IsEmpty() const
	{
		return _size == 0;
	}

	unsigned long GetSize() const
	{
		return _size;
	}

	void Enqueue(const T& value)
	{
		if (_size == _capacity)
		{
			resize(_capacity == 0 ? 1 : _capacity * 2);
		}

		// add to the back of the heap
		_data[_size++] = value;
		// move it up to the right place
		siftUp(_size - 1);
	}

	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("List is empty");
		}

		// take the first element (max)
		int result = std::move(_data[0]);
		// move the last element to the first place
		_data[0] = std::move(_data[--_size]);
		// move the first element down to the right place
		siftDown(0);
		return result;
	}

	T Peek() const
	{
		if (IsEmpty())
		{
			throw std::runtime_error("Heap is empty!");
		}

		return _data[0];
	}

	void Print() const
	{
		int nextLevel = 0;
		for (int i = 0; i < _size; i++)
		{
			std::cout << _data[i];
			if (i == nextLevel)
			{
				std::cout << "\n";
				nextLevel += nextLevel + 2;
			}
			else if (i % 2 == 1)
			{
				// middle member
				std::cout << " ^ ";
			}
			else
			{
				std::cout << "   ";
			}
		}
	}

private:
	unsigned long parent(unsigned long i) const { return (i - 1) / 2; }
	unsigned long leftChild(unsigned long index) const 
	{
		return index * 2 + 1;
	}

	unsigned long rightChild(unsigned long index) const
	{
		return index * 2 + 2;
	}

	void resize(unsigned long newCapacity)
	{
		std::unique_ptr<T[]> newData(new T[newCapacity]);
		for (unsigned long i = 0; i < _size; i++)
		{
			newData[i] = std::move(_data[i]);
		}
		_data = std::move(newData);
		_capacity = newCapacity;
	}

	// Move i-th element up the heap until it's in the right place
	void siftUp(unsigned long i) {
		while (i > 0 && _data[parent(i)] < _data[i]) {
			swap(parent(i), i);
			i = parent(i);
		}
	}

	// Move i-th element down the heap until it's in the right place
	void siftDown(unsigned long i) {
		int maxIndex = i;
		int l = leftChild(i);
		if (l < _size && _data[l] > _data[maxIndex]) {
			maxIndex = l;
		}
		int r = rightChild(i);
		if (r < _size && _data[r] > _data[maxIndex]) {
			maxIndex = r;
		}
		if (i != maxIndex) {
			swap(i, maxIndex);
			siftDown(maxIndex);
		}
	}

	void swap(unsigned long i, unsigned long j)
	{
		auto temp = std::move(_data[i]);
		_data[i] = std::move(_data[j]);
		_data[j] = std::move(temp);
	}
};

