#include <iostream>
#include "NumericVector.h"

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

    return 0;
}
