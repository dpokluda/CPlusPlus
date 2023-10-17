#include <iostream>
#include <vector>

void Swap(std::vector<int> &data, int first, int second);

std::vector<int> Sort(const std::vector<int> data) {
    std::vector<int> arr = data;

    for (auto i = 0; i < arr.size(); i++) {
        for (auto j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr, j, j + 1);
            }
        }
    }

    return arr;
}

void Swap(std::vector<int> &data, int first, int second) {
    auto temp = data[first];
    data[first] = data[second];
    data[second] = temp;
}

int main() {
    std::cout << "Bubble sort:" << std::endl;
    std::vector<int> data = {5, 4, 3, 2, 1};

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
