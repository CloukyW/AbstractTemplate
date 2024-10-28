// NumericVector.h
#ifndef NUMERICVECTOR_H
#define NUMERICVECTOR_H

#include "AbstractVector.h"

template <typename T>
class NumericVector : public AbstractVector<T> {
public:
    // ���캯��
    NumericVector(int capacity = 10) : AbstractVector<T>(capacity) {}

    // ʵ�� push_back
    void push_back(const T& value) override {
        if (this->size_ >= this->capacity_) {
            this->resize(this->capacity_ * 2);
        }
        this->data_[this->size_++] = value;
    }

    // ʵ�� pop_back
    void pop_back() override {
        if (this->size_ == 0) {
            throw std::underflow_error("Vector is empty. Cannot pop.");
        }
        --(this->size_);
    }

    // ��д display����ѡ��
    void display() const override {
        std::cout << "NumericVector: ";
        AbstractVector<T>::display();
        std::cout << std::endl;
    }
};

#endif // NUMERICVECTOR_H
