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

    // 私有的辅助函数用于动态调整数组大小
    void resize(size_t new_capacity);

public:
    // 默认构造函数
    Vector();

    // 用数组构造Vector
    Vector(const T* arr, size_t size);

    // 复制构造函数
    Vector(const Vector& other);

    // 虚析构函数
    virtual ~Vector();

    // 赋值运算符重载
    Vector& operator=(const Vector& other);

    // 索引运算符重载
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // 加法运算符重载
    Vector operator+(const Vector& other) const;
    Vector& operator+=(const Vector& other);

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

    // 抽象功能 (纯虚函数)
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual size_t get_capacity() const = 0;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual T& at(size_t index) = 0;
    virtual const T& at(size_t index) const = 0;

    // 预留内存空间
    void reserve(size_t new_capacity);

    // 释放超过size的内存空间
    void shrink_to_fit();

    // 插入和删除操作
    void insert(size_t index, const T& item);
    void insert(size_t index, size_t count, const T& item);
    void erase(size_t index);
    void erase(size_t index, size_t count);

    // 交换两个vector的数据元素
    void swap(Vector& other);
};

// 实现部分保持不变，仅在需要的地方将函数标记为虚函数或纯虚函数。
// 例如：size()、empty()、push()、pop() 等接口可以由派生类实现。
// 
// 需要虚析构函数的类中应明确声明析构函数为 `virtual`，这样在继承结构中可以支持多态。
// 也可以将其他部分代码保持不变。

#endif
