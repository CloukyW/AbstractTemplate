// StringVector.h
#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H

#include "AbstractVector.h"
#include <string>

class StringVector : public Vector<std::string> {
public:
    // 默认构造函数
    StringVector() : Vector<std::string>() {}

    // 用数组构造StringVector
    StringVector(const std::string* arr, std::size_t size) : Vector<std::string>(arr, size) {}

    // 复制构造函数
    StringVector(const StringVector& other) : Vector<std::string>(other) {}

    // 移动构造函数
    StringVector(StringVector&& other) noexcept : Vector<std::string>(std::move(other)) {}

    // 赋值运算符重载
    StringVector& operator=(const StringVector& other) {
        Vector<std::string>::operator=(other);
        return *this;
    }

    // 移动赋值运算符重载
    StringVector& operator=(StringVector&& other) noexcept {
        Vector<std::string>::operator=(std::move(other));
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

    // 添加字符串特定的功能，例如拼接所有字符串
    std::string concatenate() const {
        std::string result;
        for (std::size_t i = 0; i < size_; ++i) {
            result += data_[i];
        }
        return result;
    }

    // 实现 operator+ 和 operator+=
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

    // 重写输出流运算符以包括特定功能
    friend std::ostream& operator<<(std::ostream& os, const StringVector& vec) {
        os << "[ ";
        for (std::size_t i = 0; i < vec.size_; ++i) {
            os << "\"" << vec.data_[i] << "\" ";
        }
        os << "]";
        return os;
    }

    // 重写输入流运算符
    friend std::istream& operator>>(std::istream& is, StringVector& vec) {
        std::string value;
        while (is >> value) {
            vec.push(value);
        }
        return is;
    }
};

#endif // STRINGVECTOR_H
