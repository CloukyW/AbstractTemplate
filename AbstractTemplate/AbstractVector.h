// AbstractVector.h
#ifndef ABSTRACTVECTOR_H
#define ABSTRACTVECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class AbstractVector {
protected:
    int size_;
    int capacity_;
    T* data_;

    // 保护的扩容函数
    void resize(int new_capacity) {
        if (new_capacity < size_) {
            throw std::invalid_argument("New capacity cannot be less than current size.");
        }
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    // 构造函数
    AbstractVector(int capacity = 10) : size_(0), capacity_(capacity), data_(new T[capacity]) {}

    // 虚析构函数
    virtual ~AbstractVector() {
        delete[] data_;
    }

    // 获取当前大小
    int size() const { return size_; }

    // 获取容量
    int capacity() const { return capacity_; }

    // 获取元素（虚函数）
    virtual T get(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range.");
        }
        return data_[index];
    }

    // 添加元素（纯虚函数）
    virtual void push_back(const T& value) = 0;

    // 移除最后一个元素（纯虚函数）
    virtual void pop_back() = 0;

    // 显示向量内容（虚函数）
    virtual void display() const {
        std::cout << "[ ";
        for (int i = 0; i < size_; ++i) {
            std::cout << data_[i] << " ";
        }
        std::cout << "]";
    }
};

#endif // ABSTRACTVECTOR_H
