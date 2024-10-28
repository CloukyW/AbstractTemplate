#pragma once
// StringVector.h
#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H

#include "AbstractVector.h"
#include <string>

template <>
class AbstractVector<std::string> {
protected:
    int size_;
    int capacity_;
    std::string* data_;

    void resize(int new_capacity) {
        if (new_capacity < size_) {
            throw std::invalid_argument("New capacity cannot be less than current size.");
        }
        std::string* new_data = new std::string[new_capacity];
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    AbstractVector(int capacity = 10) : size_(0), capacity_(capacity), data_(new std::string[capacity]) {}

    virtual ~AbstractVector() {
        delete[] data_;
    }

    int size() const { return size_; }

    int capacity() const { return capacity_; }

    virtual std::string get(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range.");
        }
        return data_[index];
    }

    virtual void push_back(const std::string& value) = 0;

    virtual void pop_back() = 0;

    virtual void display() const {
        std::cout << "[ ";
        for (int i = 0; i < size_; ++i) {
            std::cout << "\"" << data_[i] << "\" ";
        }
        std::cout << "]";
    }
};

class StringVector : public AbstractVector<std::string> {
public:
    StringVector(int capacity = 10) : AbstractVector<std::string>(capacity) {}

    void push_back(const std::string& value) override {
        if (size_ >= capacity_) {
            resize(capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void pop_back() override {
        if (size_ == 0) {
            throw std::underflow_error("StringVector is empty. Cannot pop.");
        }
        --size_;
    }

    void display() const override {
        std::cout << "StringVector: ";
        AbstractVector<std::string>::display();
        std::cout << std::endl;
    }
};

#endif // STRINGVECTOR_H
