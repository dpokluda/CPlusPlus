#include <iostream>
#include <vector>

void Swap(std::vector<int> &arr, int first, int second);

void Heapify(std::vector<int> &arr, int n, int i);

std::vector<int> Sort(const std::vector<int> &data) {
    std::vector<int> arr{data};
    int n = arr.size();

    // Build max-heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        Swap(arr, 0, i);

        // call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }

    return arr;
}

void Heapify(std::vector<int> &arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        Swap(arr, i, largest);

        // Recursively heapify the affected sub-tree
        Heapify(arr, n, largest);
    }
}

void Swap(std::vector<int> &arr, int first, int second) {
    auto temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int main() {
    std::cout << "Heap sort:" << std::endl;
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
