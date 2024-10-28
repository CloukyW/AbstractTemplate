#include "AbstractVector.h"
#include <string>

class IntVector : public Vector<int> {
public:
    IntVector() : Vector() {}

    // �����鹹��IntVector
    IntVector(const int* arr, size_t size) : Vector(arr, size) {}

    // �ж��Ƿ�Ϊ��
    bool empty() const override {
        return element_count == 0;
    }

    // ����Ԫ�ظ���
    size_t size() const override {
        return element_count;
    }

    // ���ص�ǰ����
    size_t get_capacity() const override {
        return capacity;
    }

    // ��ĩβ���Ԫ��
    void push(const int& item) override {
        if (element_count >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[element_count++] = item;
    }

    // �Ƴ�ĩβԪ��
    int pop() override {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return data[--element_count];
    }

    // ����ָ��λ�õ�Ԫ��
    int& at(size_t index) override {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const int& at(size_t index) const override {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

class DoubleVector : public Vector<double> {
public:
    DoubleVector() : Vector() {}

    // �����鹹��DoubleVector
    DoubleVector(const double* arr, size_t size) : Vector(arr, size) {}

    bool empty() const override {
        return element_count == 0;
    }

    size_t size() const override {
        return element_count;
    }

    size_t get_capacity() const override {
        return capacity;
    }

    void push(const double& item) override {
        if (element_count >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[element_count++] = item;
    }

    double pop() override {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return data[--element_count];
    }

    double& at(size_t index) override {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const double& at(size_t index) const override {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

#pragma once
