#pragma once

#include <memory>

template<typename T>
class List {
private:
    std::unique_ptr<T[]> data;
    unsigned long size_;
    unsigned long capacity_;

    void resize(unsigned long new_capacity) {
        if (new_capacity < size_) return;

        std::unique_ptr<T[]> new_data(new T[new_capacity]);
        for (unsigned long i = 0; i < size_; ++i) {
            new_data[i] = std::move(data[i]);
        }

        data = std::move(new_data);
        capacity_ = new_capacity;
    }

public:
    List() : data(nullptr), size_(0), capacity_(0) {}

    unsigned long size() const { return size_; }
    unsigned long capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        data[size_++] = value;
    }

    void pop_back() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }

        --size_;
    }

    T& operator[](unsigned long index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    const T& operator[](unsigned long index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    void clear() {
        data.reset();
        size_ = 0;
        capacity_ = 0;
    }
};
