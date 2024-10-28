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

    // ˽�еĸ����������ڶ�̬���������С
    void resize(std::size_t new_capacity);

public:
    // Ĭ�Ϲ��캯��
    Vector();

    // �����鹹��Vector
    Vector(const T* arr, std::size_t size);

    // ���ƹ��캯��
    Vector(const Vector& other);

    // �ƶ����캯��
    Vector(Vector&& other) noexcept;

    // ��ֵ���������
    Vector& operator=(const Vector& other);

    // �ƶ���ֵ���������
    Vector& operator=(Vector&& other) noexcept;

    // ����������
    virtual ~Vector() = default;

    // �������������
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    // ǰ�õ������������
    Vector& operator++();

    // ���õ������������
    Vector operator++(int);

    // ��������������
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);

    // ���������������
    template<typename U>
    friend std::istream& operator>>(std::istream& is, Vector<U>& vec);

    // ���麯��������ӿڣ�
    virtual bool empty() const = 0;
    virtual std::size_t size() const = 0;
    virtual std::size_t get_capacity() const = 0;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual T& at(std::size_t index) = 0;
    virtual const T& at(std::size_t index) const = 0;

    // Ԥ���ڴ�ռ�
    void reserve(std::size_t new_capacity);

    // �ͷų���size���ڴ�ռ�
    void shrink_to_fit();

    // �����ɾ������
    void insert(std::size_t index, const T& item);
    void insert(std::size_t index, std::size_t count, const T& item);
    void erase(std::size_t index);
    void erase(std::size_t index, std::size_t count);

    // ��������vector������Ԫ��
    void swap(Vector& other) noexcept;
};

// ʵ�ֲ��֣�ͨ��Ӧ��ͬһͷ�ļ���ʵ��ģ���ࣩ

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
    // �ƶ�Ԫ��
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
    // �ƶ�Ԫ��
    for (std::size_t i = size_ + count - 1; i >= index + count && i < size_ + count; --i) {
        data_[i] = data_[i - count];
        if (i == index + count) break; // ��ֹ size_t ����
    }
    // ������Ԫ��
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
