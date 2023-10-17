#include <iostream>
#include <vector>

void MergeSort(std::vector<int> &arr, int left, int right);

void Merge(std::vector<int> &arr, int left, int middle, int right);

std::vector<int> Sort(const std::vector<int> &data) {
    std::vector<int> arr{data};

    MergeSort(arr, 0, arr.size() - 1);
    return arr;
}

void MergeSort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);
        Merge(arr, left, middle, right);
    }
}

void Merge(std::vector<int> &arr, int left, int middle, int right) {
    int lsize = middle - left + 1;
    int rsize = right - middle;

    // Create temp arrays
    std::vector<int> la(lsize);
    std::vector<int> ra(rsize);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < lsize; i++)
        la[i] = arr[left + i];
    for (int j = 0; j < rsize; j++)
        ra[j] = arr[middle + 1 + j];

    //merge
    int li = 0;
    int ri = 0;
    int k = left;
    while (li < la.size() && ri < ra.size()) {
        if (la[li] <= ra[ri]) {
            arr[k] = la[li];
            li++;
        } else {
            arr[k] = ra[ri];
            ri++;
        }

        k++;
    }

    //copy rest
    while (li < la.size()) {
        arr[k] = la[li];
        li++;
        k++;
    }
    while (ri < ra.size()) {
        arr[k] = ra[ri];
        ri++;
        k++;
    }
}

int main() {
    std::cout << "Merge sort:" << std::endl;
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
