#include "Queue.h"

#include <iostream>

template <typename T>
void Queue<T>::Print() const
{
	std::cout << _data << "\n";
}