#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& arr, int left, int right);

void Swap(std::vector<int>& data, int first, int second);

int Partition(std::vector<int>& data, int left, int right);

std::vector<int> Sort(const std::vector<int>& data)
{
	std::vector<int> arr{data};

	QuickSort(arr, 0, arr.size() - 1);
	return arr;
}

void QuickSort(std::vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		// pi is partitioning index, arr[p]
		// is now at right place
		int middle = Partition(arr, left, right);

		// Separately sort elements before
		// partition and after partition
		QuickSort(arr, left, middle - 1);
		QuickSort(arr, middle + 1, right);
	}
}

int Partition(std::vector<int>& data, int left, int right)
{
	// pivot
	int pivot = data[right];

	// Index of smaller element and
	// indicates the right position
	// of pivot found so far
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++)
	{
		// If current element is smaller
		// than the pivot
		if (data[j] < pivot)
		{
			i++;
			Swap(data, i, j);
		}
	}

	Swap(data, i + 1, right);

	return (i + 1);
}

void Swap(std::vector<int>& data, int first, int second)
{
	auto temp = data[first];
	data[first] = data[second];
	data[second] = temp;
}

int main()
{
	std::cout << "Quick sort:" << std::endl;
	std::vector<int> data = {5, 4, 3, 2, 1};

	auto sorted = Sort(data);

	std::cout << "Original:" << std::endl;
	for (auto i = 0; i < 5; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Sorted:" << std::endl;
	for (auto i = 0; i < 5; i++)
	{
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
