// NumericVector.h
#ifndef NUMERIC_VECTOR_H
#define NUMERIC_VECTOR_H

#include "AbstractVector.h"

// IntVector ��
class IntVector : public Vector<int> {
public:
    // Ĭ�Ϲ��캯��
    IntVector() : Vector<int>() {}

    // �����鹹��IntVector
    IntVector(const int* arr, std::size_t size) : Vector<int>(arr, size) {}

    // ���ƹ��캯��
    IntVector(const IntVector& other) : Vector<int>(other) {}

    // �ƶ����캯��
    IntVector(IntVector&& other) noexcept : Vector<int>(std::move(other)) {}

    // ��ֵ���������
    IntVector& operator=(const IntVector& other) {
        Vector<int>::operator=(other);
        return *this;
    }

    // �ƶ���ֵ���������
    IntVector& operator=(IntVector&& other) noexcept {
        Vector<int>::operator=(std::move(other));
        return *this;
    }

    // ʵ�ִ��麯��
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

    // ʵ�� operator+ �� operator+=
    IntVector operator+(const IntVector& other) const {
        IntVector result;
        result.reserve(this->size_ + other.size_);
        for (std::size_t i = 0; i < this->size_; ++i) {
            result.push(this->data_[i]);
        }
        for (std::size_t i = 0; i < other.size_; ++i) {
            result.push(other.data_[i]);
        }
        return result;
    }

    IntVector& operator+=(const IntVector& other) {
        for (std::size_t i = 0; i < other.size_; ++i) {
            push(other.data_[i]);
        }
        return *this;
    }

    // ʵ��ǰ�õ��������
    IntVector& operator++() {
        for (std::size_t i = 0; i < size_; ++i) {
            ++data_[i];
        }
        return *this;
    }

    // ʵ�ֺ��õ��������
    IntVector operator++(int) {
        IntVector temp = *this;
        ++(*this);
        return temp;
    }
};

class DoubleVector : public Vector<double> {
public:
    // Ĭ�Ϲ��캯��
    DoubleVector() : Vector<double>() {}

    // �����鹹��DoubleVector
    DoubleVector(const double* arr, std::size_t size) : Vector<double>(arr, size) {}

    // ���ƹ��캯��
    DoubleVector(const DoubleVector& other) : Vector<double>(other) {}

    // �ƶ����캯��
    DoubleVector(DoubleVector&& other) noexcept : Vector<double>(std::move(other)) {}

    // ��ֵ���������
    DoubleVector& operator=(const DoubleVector& other) {
        Vector<double>::operator=(other);
        return *this;
    }

    // �ƶ���ֵ���������
    DoubleVector& operator=(DoubleVector&& other) noexcept {
        Vector<double>::operator=(std::move(other));
        return *this;
    }

    // ʵ�ִ��麯��
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

    // ʵ�� operator+ �� operator+=
    DoubleVector operator+(const DoubleVector& other) const {
        DoubleVector result;
        result.reserve(this->size_ + other.size_);
        for (std::size_t i = 0; i < this->size_; ++i) {
            result.push(this->data_[i]);
        }
        for (std::size_t i = 0; i < other.size_; ++i) {
            result.push(other.data_[i]);
        }
        return result;
    }

    DoubleVector& operator+=(const DoubleVector& other) {
        for (std::size_t i = 0; i < other.size_; ++i) {
            push(other.data_[i]);
        }
        return *this;
    }

    // ʵ��ǰ�õ��������
    DoubleVector& operator++() {
        for (std::size_t i = 0; i < size_; ++i) {
            ++data_[i];
        }
        return *this;
    }

    // ʵ�ֺ��õ��������
    DoubleVector operator++(int) {
        DoubleVector temp = *this;
        ++(*this);
        return temp;
    }
};


#endif // NUMERIC_VECTOR_H
