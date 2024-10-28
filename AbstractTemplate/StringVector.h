#include "AbstractVector.h"
#include <string>

class StringVector : public Vector<std::string> {
public:
    StringVector() : Vector() {}

    // 用数组构造StringVector
    StringVector(const std::string* arr, size_t size) : Vector(arr, size) {}

    bool empty() const override {
        return element_count == 0;
    }

    size_t size() const override {
        return element_count;
    }

    size_t get_capacity() const override {
        return capacity;
    }

    void push(const std::string& item) override {
        if (element_count >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[element_count++] = item;
    }

    std::string pop() override {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return data[--element_count];
    }

    std::string& at(size_t index) override {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const std::string& at(size_t index) const override {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

}; 

#pragma once
