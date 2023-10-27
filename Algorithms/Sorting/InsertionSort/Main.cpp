#include <iostream>
#include <vector>

std::vector<int> Sort(const std::vector<int>& data) {
    std::vector<int> arr{ data };

    for (size_t i = 1; i < arr.size(); i++) {
	    const int key = arr[i];
        size_t j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = key;
    }

    return arr;
}

int main() {
    std::cout << "Insertion sort:" << std::endl;
    std::vector<int> data = { 5, 4, 3, 2, 1 };

    auto sorted = Sort(data);

    std::cout << "Original:" << std::endl;
    for (auto i = 0; i < 5; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted:" << std::endl;
    for (auto i = 0; i < 5; i++) {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
