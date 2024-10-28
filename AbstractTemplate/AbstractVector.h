// AbstractVector.h
#ifndef ABSTRACT_VECTOR_H
#define ABSTRACT_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <memory>

template<typename T>
class Vector {
protected:
    std::unique_ptr<T[]> data_;
    std::size_t size_;
    std::size_t capacity_;

    // 私有的辅助函数用于动态调整数组大小
    void resize(std::size_t new_capacity);

public:
    // 默认构造函数
    Vector();

    // 用数组构造Vector
    Vector(const T* arr, std::size_t size);

    // 复制构造函数
    Vector(const Vector& other);

    // 移动构造函数
    Vector(Vector&& other) noexcept;

    // 赋值运算符重载
    Vector& operator=(const Vector& other);

    // 移动赋值运算符重载
    Vector& operator=(Vector&& other) noexcept;

    // 虚析构函数
    virtual ~Vector() = default;

    // 索引运算符重载
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    // 前置递增运算符重载
    Vector& operator++();

    // 后置递增运算符重载
    Vector operator++(int);

    // 输出流运算符重载
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);

    // 输入流运算符重载
    template<typename U>
    friend std::istream& operator>>(std::istream& is, Vector<U>& vec);

    // 纯虚函数（抽象接口）
    virtual bool empty() const = 0;
    virtual std::size_t size() const = 0;
    virtual std::size_t get_capacity() const = 0;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual T& at(std::size_t index) = 0;
    virtual const T& at(std::size_t index) const = 0;

    // 预留内存空间
    void reserve(std::size_t new_capacity);

    // 释放超过size的内存空间
    void shrink_to_fit();

    // 插入和删除操作
    void insert(std::size_t index, const T& item);
    void insert(std::size_t index, std::size_t count, const T& item);
    void erase(std::size_t index);
    void erase(std::size_t index, std::size_t count);

    // 交换两个vector的数据元素
    void swap(Vector& other) noexcept;
};

// 实现部分（通常应在同一头文件中实现模板类）

template<typename T>
Vector<T>::Vector() : data_(nullptr), size_(0), capacity_(0) {}

template<typename T>
Vector<T>::Vector(const T* arr, std::size_t size)
    : data_(std::make_unique<T[]>(size)), size_(size), capacity_(size) {
    std::copy(arr, arr + size, data_.get());
}

template<typename T>
Vector<T>::Vector(const Vector& other)
    : data_(std::make_unique<T[]>(other.capacity_)),
    size_(other.size_),
    capacity_(other.capacity_) {
    std::copy(other.data_.get(), other.data_.get() + other.size_, data_.get());
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept
    : data_(std::move(other.data_)),
    size_(other.size_),
    capacity_(other.capacity_) {
    other.size_ = 0;
    other.capacity_ = 0;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        if (other.size_ > capacity_) {
            auto new_data = std::make_unique<T[]>(other.capacity_);
            std::copy(other.data_.get(), other.data_.get() + other.size_, new_data.get());
            data_ = std::move(new_data);
            capacity_ = other.capacity_;
        }
        else {
            std::copy(other.data_.get(), other.data_.get() + other.size_, data_.get());
        }
        size_ = other.size_;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
    if (this != &other) {
        data_ = std::move(other.data_);
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

template<typename T>
T& Vector<T>::operator[](std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<typename T>
const T& Vector<T>::operator[](std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<typename T>
Vector<T>& Vector<T>::operator++() {
    for (std::size_t i = 0; i < size_; ++i) {
        ++data_[i];
    }
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator++(int) {
    Vector temp = *this;
    ++(*this);
    return temp;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec) {
    os << "[ ";
    for (std::size_t i = 0; i < vec.size_; ++i) {
        os << vec[i] << " ";
    }
    os << "]";
    return os;
}

template<typename U>
std::istream& operator>>(std::istream& is, Vector<U>& vec) {
    U value;
    while (is >> value) {
        vec.push(value);
    }
    return is;
}

template<typename T>
void Vector<T>::reserve(std::size_t new_capacity) {
    if (new_capacity > capacity_) {
        auto new_data = std::make_unique<T[]>(new_capacity);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        data_ = std::move(new_data);
        capacity_ = new_capacity;
    }
}

template<typename T>
void Vector<T>::shrink_to_fit() {
    if (capacity_ > size_) {
        auto new_data = std::make_unique<T[]>(size_);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        data_ = std::move(new_data);
        capacity_ = size_;
    }
}

template<typename T>
void Vector<T>::swap(Vector& other) noexcept {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

template<typename T>
void Vector<T>::resize(std::size_t new_capacity) {
    reserve(new_capacity);
}

template<typename T>
void Vector<T>::insert(std::size_t index, const T& item) {
    if (index > size_) {
        throw std::out_of_range("Index out of range");
    }
    if (size_ >= capacity_) {
        resize(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    // 移动元素
    for (std::size_t i = size_; i > index; --i) {
        data_[i] = data_[i - 1];
    }
    data_[index] = item;
    ++size_;
}

template<typename T>
void Vector<T>::insert(std::size_t index, std::size_t count, const T& item) {
    if (index > size_) {
        throw std::out_of_range("Index out of range");
    }
    if (size_ + count > capacity_) {
        resize(std::max(capacity_ * 2, size_ + count));
    }
    // 移动元素
    for (std::size_t i = size_ + count - 1; i >= index + count && i < size_ + count; --i) {
        data_[i] = data_[i - count];
        if (i == index + count) break; // 防止 size_t 下溢
    }
    // 插入新元素
    for (std::size_t i = 0; i < count; ++i) {
        data_[index + i] = item;
    }
    size_ += count;
}

template<typename T>
void Vector<T>::erase(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    for (std::size_t i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }
    --size_;
}

template<typename T>
void Vector<T>::erase(std::size_t index, std::size_t count) {
    if (index + count > size_) {
        throw std::out_of_range("Index out of range");
    }
    for (std::size_t i = index; i < size_ - count; ++i) {
        data_[i] = data_[i + count];
    }
    size_ -= count;
}

#endif // ABSTRACT_VECTOR_H
