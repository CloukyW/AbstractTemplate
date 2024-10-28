#include "AbstractVector.h"

// Ĭ�Ϲ��캯��
template<typename T>
Vector<T>::Vector() : data(nullptr), element_count(0), capacity(0) {}

// �����鹹��Vector
template<typename T>
Vector<T>::Vector(const T* arr, size_t size) : data(nullptr), element_count(size), capacity(size) {
    data = new T[capacity];
    std::copy(arr, arr + size, data);
}

// ���ƹ��캯��
template<typename T>
Vector<T>::Vector(const Vector& other) : data(nullptr), element_count(other.element_count), capacity(other.capacity) {
    data = new T[capacity];
    std::copy(other.data, other.data + other.element_count, data);
}

// ����������
template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

// ��ֵ���������
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        T* new_data = new T[other.capacity];
        std::copy(other.data, other.data + other.element_count, new_data);
        delete[] data;
        data = new_data;
        element_count = other.element_count;
        capacity = other.capacity;
    }
    return *this;
}

// �������������
template<typename T>
T& Vector<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
    return data[index];
}

// �ӷ����������
template<typename T>
Vector<T> Vector<T>::operator+(const Vector& other) const {
    Vector result(*this);
    result += other;
    return result;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector& other) {
    if (element_count + other.element_count > capacity) {
        reserve(element_count + other.element_count);
    }
    std::copy(other.data, other.data + other.element_count, data + element_count);
    element_count += other.element_count;
    return *this;
}

// ǰ�õ������������
template<typename T>
Vector<T>& Vector<T>::operator++() {
    for (size_t i = 0; i < element_count; ++i) {
        ++data[i];
    }
    return *this;
}

// ���õ������������
template<typename T>
Vector<T> Vector<T>::operator++(int) {
    Vector temp(*this);
    ++(*this);
    return temp;
}

// ��������������
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    for (size_t i = 0; i < vec.element_count; ++i) {
        os << vec.data[i] << ' ';
    }
    return os;
}

// ���������������
template<typename T>
std::istream& operator>>(std::istream& is, Vector<T>& vec) {
    T item;
    while (is >> item) {
        vec.push(item);
    }
    return is;
}

// Ԥ���ڴ�ռ�
template<typename T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity > capacity) {
        T* new_data = new T[new_capacity];
        std::copy(data, data + element_count, new_data);
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

// �ͷų���size���ڴ�ռ�
template<typename T>
void Vector<T>::shrink_to_fit() {
    if (capacity > element_count) {
        T* new_data = new T[element_count];
        std::copy(data, data + element_count, new_data);
        delete[] data;
        data = new_data;
        capacity = element_count;
    }
}

// �����ɾ������
template<typename T>
void Vector<T>::insert(size_t index, const T& item) {
    if (index > element_count) {
        throw std::out_of_range("Index out of range");
    }
    if (element_count >= capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    std::copy_backward(data + index, data + element_count, data + element_count + 1);
    data[index] = item;
    ++element_count;
}

template<typename T>
void Vector<T>::insert(size_t index, size_t count, const T& item) {
    if (index > element_count) {
        throw std::out_of_range("Index out of range");
    }
    if (element_count + count > capacity) {
        reserve(element_count + count);
    }
    std::copy_backward(data + index, data + element_count, data + element_count + count);
    std::fill(data + index, data + index + count, item);
    element_count += count;
}

template<typename T>
void Vector<T>::erase(size_t index) {
    if (index >= element_count) {
        throw std::out_of_range("Index out of range");
    }
    std::copy(data + index + 1, data + element_count, data + index);
    --element_count;
}

template<typename T>
void Vector<T>::erase(size_t index, size_t count) {
    if (index + count > element_count) {
        throw std::out_of_range("Index out of range");
    }
    std::copy(data + index + count, data + element_count, data + index);
    element_count -= count;
}

// ��������vector������Ԫ��
template<typename T>
void Vector<T>::swap(Vector& other) {
    std::swap(data, other.data);
    std::swap(element_count, other.element_count);
    std::swap(capacity, other.capacity);
}
