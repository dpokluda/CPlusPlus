#pragma once
#include <memory>

template<typename T>
class Stack {
private:
    std::unique_ptr<T[]> data;
    unsigned long top_index;
    unsigned long capacity_;

    void resize(unsigned long new_capacity) {
        std::unique_ptr<T[]> new_data(new T[new_capacity]);
        for (unsigned long i = 0; i < top_index; ++i) {
            new_data[i] = std::move(data[i]);
        }

        data = std::move(new_data);
        capacity_ = new_capacity;
    }

public:
    Stack() : data(nullptr), top_index(0), capacity_(0) {}

    unsigned long size() const { return top_index; }
    unsigned long capacity() const { return capacity_; }
    bool empty() const { return top_index == 0; }

    void push(const T& value) {
        if (top_index == capacity_) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        data[top_index++] = value;
    }

    const T& pop() {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }

        return data[--top_index];
    }

    const T& peek() const {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }

        return data[top_index - 1];
    }

    void clear() {
        data.reset();
        top_index = 0;
        capacity_ = 0;
    }
};
