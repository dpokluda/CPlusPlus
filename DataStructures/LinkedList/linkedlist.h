#pragma once
#include <memory>
#include <iostream>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;

        Node(T value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    void pushFront(T value) {
        auto newNode = std::make_unique<Node>(value);
        if (head) {
            newNode->next = std::move(head);
        }
        head = std::move(newNode);
    }

    void append(T value) {
        auto newNode = std::make_unique<Node>(value);
        if (!head) {
            head = std::move(newNode);
            return;
        }

        Node* current = head.get();
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
    }

    bool remove(T value) {
        if (!head) return false;

        if (head->data == value) {
            head = std::move(head->next);
            return true;
        }

        Node* current = head.get();
        while (current->next && current->next->data != value) {
            current = current->next.get();
        }

        if (current->next) {
            current->next = std::move(current->next->next);
            return true;
        }
        return false;
    }

    void print() const {
        Node* current = head.get();
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "nullptr" << std::endl;
    }
};
