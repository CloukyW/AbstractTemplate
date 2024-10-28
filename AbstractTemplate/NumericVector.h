#ifndef NUMERIC_VECTOR_H
#define NUMERIC_VECTOR_H

#include "AbstractVector.h"

// IntVector 类
class IntVector : public Vector<int> {
public:
    // 默认构造函数
    IntVector() : Vector<int>() {}

    // 用数组构造IntVector
    IntVector(const int* arr, std::size_t size) : Vector<int>(arr, size) {}

    // 复制构造函数
    IntVector(const IntVector& other) : Vector<int>(other) {}

    // 移动构造函数
    IntVector(IntVector&& other) noexcept : Vector<int>(std::move(other)) {}

    // 赋值运算符重载
    IntVector& operator=(const IntVector& other) {
        Vector<int>::operator=(other);
        return *this;
    }

    // 移动赋值运算符重载
    IntVector& operator=(IntVector&& other) noexcept {
        Vector<int>::operator=(std::move(other));
        return *this;
    }

    // 实现纯虚函数
    bool empty() const override {
        return size_ == 0;
    }

    std::size_t size() const override {
        return size_;
    }

    std::size_t get_capacity() const override {
        return capacity_;
    }

    void push(const int& item) override {
        if (size_ >= capacity_) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = item;
    }

    int pop() override {
        if (empty()) {
            throw std::out_of_range("IntVector is empty");
        }
        return data_[--size_];
    }

    int& at(std::size_t index) override {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const int& at(std::size_t index) const override {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
};

// DoubleVector 类
class DoubleVector : public Vector<double> {
public:
    // 默认构造函数
    DoubleVector() : Vector<double>() {}

    // 用数组构造DoubleVector
    DoubleVector(const double* arr, std::size_t size) : Vector<double>(arr, size) {}

    // 复制构造函数
    DoubleVector(const DoubleVector& other) : Vector<double>(other) {}

    // 移动构造函数
    DoubleVector(DoubleVector&& other) noexcept : Vector<double>(std::move(other)) {}

    // 赋值运算符重载
    DoubleVector& operator=(const DoubleVector& other) {
        Vector<double>::operator=(other);
        return *this;
    }

    // 移动赋值运算符重载
    DoubleVector& operator=(DoubleVector&& other) noexcept {
        Vector<double>::operator=(std::move(other));
        return *this;
    }

    // 实现纯虚函数
    bool empty() const override {
        return size_ == 0;
    }

    std::size_t size() const override {
        return size_;
    }

    std::size_t get_capacity() const override {
        return capacity_;
    }

    void push(const double& item) override {
        if (size_ >= capacity_) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = item;
    }

    double pop() override {
        if (empty()) {
            throw std::out_of_range("DoubleVector is empty");
        }
        return data_[--size_];
    }

    double& at(std::size_t index) override {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const double& at(std::size_t index) const override {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
};

#endif // NUMERIC_VECTOR_H
