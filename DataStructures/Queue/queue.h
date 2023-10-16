#pragma once
#include <memory>

template<typename T>
class Queue {
private:
    std::unique_ptr<T[]> data;
    unsigned long head;
    unsigned long tail;
    unsigned long capacity_;

    void resize(unsigned long new_capacity) {
        std::unique_ptr<T[]> new_data{new T[new_capacity]};

        unsigned long current_size = size();
        for (unsigned long i = 0; i < current_size; ++i) {
            new_data[i] = std::move(data[(head + i) % capacity_]);
        }

        head = 0;
        tail = current_size;
        data = std::move(new_data);
        capacity_ = new_capacity;
    }

public:
    Queue() : data(nullptr), head(0), tail(0), capacity_(0) {}

    unsigned long size() const {
        if (tail >= head)
            return tail - head;
        return capacity_ - head + tail;
    }

    unsigned long capacity() const { return capacity_; }
    bool empty() const { return head == tail; }

    void enqueue(const T& value) {
        if (size() == capacity_ - 1) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        data[tail] = value;
        tail = (tail + 1) % capacity_;
    }

    void dequeue() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }

        head = (head + 1) % capacity_;
    }

    T& front() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }

        return data[head];
    }

    const T& front() const {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }

        return data[head];
    }

    void clear() {
        data.reset();
        head = 0;
        tail = 0;
        capacity_ = 0;
    }
};
