// StringVector.h
#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H

#include "AbstractVector.h"
#include <string>

class StringVector : public Vector<std::string> {
public:
    // Ĭ�Ϲ��캯��
    StringVector() : Vector<std::string>() {}

    // �����鹹��StringVector
    StringVector(const std::string* arr, std::size_t size) : Vector<std::string>(arr, size) {}

    // ���ƹ��캯��
    StringVector(const StringVector& other) : Vector<std::string>(other) {}

    // �ƶ����캯��
    StringVector(StringVector&& other) noexcept : Vector<std::string>(std::move(other)) {}

    // ��ֵ���������
    StringVector& operator=(const StringVector& other) {
        Vector<std::string>::operator=(other);
        return *this;
    }

    // �ƶ���ֵ���������
    StringVector& operator=(StringVector&& other) noexcept {
        Vector<std::string>::operator=(std::move(other));
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

    void push(const std::string& item) override {
        if (size_ >= capacity_) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = item;
    }

    std::string pop() override {
        if (empty()) {
            throw std::out_of_range("StringVector is empty");
        }
        return data_[--size_];
    }

    std::string& at(std::size_t index) override {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const std::string& at(std::size_t index) const override {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    // ����ַ����ض��Ĺ��ܣ�����ƴ�������ַ���
    std::string concatenate() const {
        std::string result;
        for (std::size_t i = 0; i < size_; ++i) {
            result += data_[i];
        }
        return result;
    }

    // ʵ�� operator+ �� operator+=
    StringVector operator+(const StringVector& other) const {
        StringVector result;
        result.reserve(this->size_ + other.size_);
        for (std::size_t i = 0; i < this->size_; ++i) {
            result.push(this->data_[i]);
        }
        for (std::size_t i = 0; i < other.size_; ++i) {
            result.push(other.data_[i]);
        }
        return result;
    }

    StringVector& operator+=(const StringVector& other) {
        for (std::size_t i = 0; i < other.size_; ++i) {
            push(other.data_[i]);
        }
        return *this;
    }

    // ��д�����������԰����ض�����
    friend std::ostream& operator<<(std::ostream& os, const StringVector& vec) {
        os << "[ ";
        for (std::size_t i = 0; i < vec.size_; ++i) {
            os << "\"" << vec.data_[i] << "\" ";
        }
        os << "]";
        return os;
    }

    // ��д�����������
    friend std::istream& operator>>(std::istream& is, StringVector& vec) {
        std::string value;
        while (is >> value) {
            vec.push(value);
        }
        return is;
    }
};

#endif // STRINGVECTOR_H
