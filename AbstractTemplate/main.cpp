// main.cpp
#include <iostream>
#include "NumericVector.h"
#include "StringVector.h"

int main() {
    // 测试 IntVector
    std::cout << "=== 测试 IntVector ===" << std::endl;
    IntVector ivec;
    try {
        ivec.push(10);
        ivec.push(20);
        ivec.push(30);
        std::cout << "IntVector: " << ivec << std::endl;

        std::cout << "Element at index 1: " << ivec.at(1) << std::endl;
        // 访问越界元素
        std::cout << "Element at index 3: " << ivec.at(3) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << std::endl;
    }

    try {
        std::cout << "Pop: " << ivec.pop() << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl;
        // 从空向量中弹出元素
        std::cout << "Pop: " << ivec.pop() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << std::endl;
    }

    // 测试 DoubleVector
    std::cout << "\n=== 测试 DoubleVector ===" << std::endl;
    DoubleVector dvec;
    try {
        dvec.push(1.1);
        dvec.push(2.2);
        dvec.push(3.3);
        std::cout << "DoubleVector: " << dvec << std::endl;

        std::cout << "Element at index 0: " << dvec.at(0) << std::endl;
        // 访问越界元素
        std::cout << "Element at index 3: " << dvec.at(3) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << std::endl;
    }

    try {
        std::cout << "Pop: " << dvec.pop() << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl;
        // 从空向量中弹出元素
        std::cout << "Pop: " << dvec.pop() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << std::endl;
    }

    // 测试 StringVector
    std::cout << "\n=== 测试 StringVector ===" << std::endl;
    StringVector svec;
    try {
        svec.push("Hello");
        svec.push(" ");
        svec.push("World");
        svec.push("!");
        std::cout << "StringVector: " << svec << std::endl;
        std::cout << "Concatenated String: " << svec.concatenate() << std::endl;

        std::cout << "Element at index 1: \"" << svec.at(1) << "\"" << std::endl;
        // 访问越界元素
        std::cout << "Element at index 4: \"" << svec.at(4) << "\"" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << std::endl;
    }

    try {
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
        // 从空向量中弹出元素
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << std::endl;
    }

    // 联合测试: 动态多态性
    std::cout << "\n=== 联合测试: 动态多态性 ===" << std::endl;

    // 使用基类指针指向派生类对象
    Vector<int>* vecPtr = new IntVector();
    Vector<double>* dvecPtr = new DoubleVector();
    Vector<std::string>* svecPtr = new StringVector();

    // 测试 IntVector 通过基类指针
    vecPtr->push(100);
    vecPtr->push(200);
    vecPtr->push(300);
    std::cout << "IntVector via Vector<int>*: " << *vecPtr << std::endl;

    // 测试 DoubleVector 通过基类指针
    dvecPtr->push(4.4);
    dvecPtr->push(5.5);
    dvecPtr->push(6.6);
    std::cout << "DoubleVector via Vector<double>*: " << *dvecPtr << std::endl;

    // 测试 StringVector 通过基类指针
    svecPtr->push("Dynamic");
    svecPtr->push(" ");
    svecPtr->push("Polymorphism");
    svecPtr->push("!");
    std::cout << "StringVector via Vector<std::string>*: " << *svecPtr << std::endl;

    // 清理
    delete vecPtr;
    delete dvecPtr;
    delete svecPtr;

    return 0;
}
