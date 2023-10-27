#include <iostream>
#include <vector>

void Swap(std::vector<int>& arr, int first, int second);

std::vector<int> Sort(const std::vector<int>& data)
{
	std::vector<int> arr{data};

	for (int i = 0; i < arr.size() - 2; i++)
	{
		auto minAt = i;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[j] < arr[minAt])
			{
				minAt = j;
			}
		}

		if (i != minAt)
		{
			Swap(arr, i, minAt);
		}
	}

	return arr;
}

void Swap(std::vector<int>& data, int first, int second)
{
	auto temp = data[first];
	data[first] = data[second];
	data[second] = temp;
}

int main()
{
	std::cout << "Selection sort:" << std::endl;
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
