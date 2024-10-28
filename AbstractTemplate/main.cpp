// main.cpp
#include <iostream>
#include "NumericVector.h"
#include "StringVector.h"

int main() {
    // ���� IntVector
    std::cout << "=== ���� IntVector ===" << std::endl;
    IntVector ivec;
    try {
        ivec.push(10);
        ivec.push(20);
        ivec.push(30);
        std::cout << "IntVector: " << ivec << std::endl;

        std::cout << "Element at index 1: " << ivec.at(1) << std::endl;
        // ����Խ��Ԫ��
        std::cout << "Element at index 3: " << ivec.at(3) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << std::endl;
    }

    try {
        std::cout << "Pop: " << ivec.pop() << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl;
        // �ӿ������е���Ԫ��
        std::cout << "Pop: " << ivec.pop() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << std::endl;
    }

    // ���� DoubleVector
    std::cout << "\n=== ���� DoubleVector ===" << std::endl;
    DoubleVector dvec;
    try {
        dvec.push(1.1);
        dvec.push(2.2);
        dvec.push(3.3);
        std::cout << "DoubleVector: " << dvec << std::endl;

        std::cout << "Element at index 0: " << dvec.at(0) << std::endl;
        // ����Խ��Ԫ��
        std::cout << "Element at index 3: " << dvec.at(3) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << std::endl;
    }

    try {
        std::cout << "Pop: " << dvec.pop() << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl;
        // �ӿ������е���Ԫ��
        std::cout << "Pop: " << dvec.pop() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << std::endl;
    }

    // ���� StringVector
    std::cout << "\n=== ���� StringVector ===" << std::endl;
    StringVector svec;
    try {
        svec.push("Hello");
        svec.push(" ");
        svec.push("World");
        svec.push("!");
        std::cout << "StringVector: " << svec << std::endl;
        std::cout << "Concatenated String: " << svec.concatenate() << std::endl;

        std::cout << "Element at index 1: \"" << svec.at(1) << "\"" << std::endl;
        // ����Խ��Ԫ��
        std::cout << "Element at index 4: \"" << svec.at(4) << "\"" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << std::endl;
    }

    try {
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
        // �ӿ������е���Ԫ��
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << std::endl;
    }

    // ���ϲ���: ��̬��̬��
    std::cout << "\n=== ���ϲ���: ��̬��̬�� ===" << std::endl;

    // ʹ�û���ָ��ָ�����������
    Vector<int>* vecPtr = new IntVector();
    Vector<double>* dvecPtr = new DoubleVector();
    Vector<std::string>* svecPtr = new StringVector();

    // ���� IntVector ͨ������ָ��
    vecPtr->push(100);
    vecPtr->push(200);
    vecPtr->push(300);
    std::cout << "IntVector via Vector<int>*: " << *vecPtr << std::endl;

    // ���� DoubleVector ͨ������ָ��
    dvecPtr->push(4.4);
    dvecPtr->push(5.5);
    dvecPtr->push(6.6);
    std::cout << "DoubleVector via Vector<double>*: " << *dvecPtr << std::endl;

    // ���� StringVector ͨ������ָ��
    svecPtr->push("Dynamic");
    svecPtr->push(" ");
    svecPtr->push("Polymorphism");
    svecPtr->push("!");
    std::cout << "StringVector via Vector<std::string>*: " << *svecPtr << std::endl;

    // ����
    delete vecPtr;
    delete dvecPtr;
    delete svecPtr;

    return 0;
}
