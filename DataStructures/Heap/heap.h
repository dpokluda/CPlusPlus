#pragma once
#include <vector>

class Heap {
private:
    std::vector<int> heap;

    int parent(int i) const { return (i - 1) / 2; }
    int leftChild(int i) const { return 2 * i + 1; }
    int rightChild(int i) const { return 2 * i + 2; }

    // Move i-th element up the heap until it's in the right place
    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // Move i-th element down the heap until it's in the right place
    void siftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        if (l < heap.size() && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }
        int r = rightChild(i);
        if (r < heap.size() && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }
        if (i != maxIndex) {
            std::swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    int getMax() const {
        if (heap.empty()) throw std::runtime_error("Heap is empty!");
        return heap[0];
    }

    void insert(int value) {
        // add to the back of the heap
        heap.push_back(value);
        // move it up to the right place
        siftUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) throw std::runtime_error("Heap is empty!");
        // take the first element (max)
        int result = heap[0];
        // move the last element to the first place
        heap[0] = heap.back();
        // remove the last element (shrink the heap)
        heap.pop_back();
        // move the first element down to the right place
        siftDown(0);
        return result;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};
