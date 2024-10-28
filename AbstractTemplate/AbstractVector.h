#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

template<typename T>
class Vector {
protected:
    T* data;
    size_t element_count;
    size_t capacity;

    // ˽�еĸ����������ڶ�̬���������С
    void resize(size_t new_capacity);

public:
    // Ĭ�Ϲ��캯��
    Vector();

    // �����鹹��Vector
    Vector(const T* arr, size_t size);

    // ���ƹ��캯��
    Vector(const Vector& other);

    // ����������
    virtual ~Vector();

    // ��ֵ���������
    Vector& operator=(const Vector& other);

    // �������������
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // �ӷ����������
    Vector operator+(const Vector& other) const;
    Vector& operator+=(const Vector& other);

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

    // ������ (���麯��)
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual size_t get_capacity() const = 0;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual T& at(size_t index) = 0;
    virtual const T& at(size_t index) const = 0;

    // Ԥ���ڴ�ռ�
    void reserve(size_t new_capacity);

    // �ͷų���size���ڴ�ռ�
    void shrink_to_fit();

    // �����ɾ������
    void insert(size_t index, const T& item);
    void insert(size_t index, size_t count, const T& item);
    void erase(size_t index);
    void erase(size_t index, size_t count);

    // ��������vector������Ԫ��
    void swap(Vector& other);
};

// ʵ�ֲ��ֱ��ֲ��䣬������Ҫ�ĵط����������Ϊ�麯�����麯����
// ���磺size()��empty()��push()��pop() �Ƚӿڿ�����������ʵ�֡�
// 
// ��Ҫ����������������Ӧ��ȷ������������Ϊ `virtual`�������ڼ̳нṹ�п���֧�ֶ�̬��
// Ҳ���Խ��������ִ��뱣�ֲ��䡣

#endif
