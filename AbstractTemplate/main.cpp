// main.cpp
#include <iostream>
#include "NumericVector.h"
#include "StringVector.h"

// ���������������ڲ��Բ���֮�������ͣ
void pause();

int main() {
    std::cout << "=== �ۺϲ��Գ��� ===\n" << std::endl;

    // 1. ���� IntVector
    std::cout << "=== ���� IntVector ===" << std::endl;
    IntVector ivec;
    try {
        std::cout << "���� push() ���Ԫ�� 11" << std::endl;
        ivec.push(11);
        std::cout << "���� push() ���Ԫ�� 45" << std::endl;
        ivec.push(45);
        std::cout << "���� push() ���Ԫ�� 14" << std::endl;
        ivec.push(14);
        std::cout << "��ʼ IntVector: " << ivec << std::endl; // ���: [ 10 20 30 ]

        // ���� empty() �� size()
        std::cout << "���� empty()" << std::endl;
        std::cout << "IntVector �Ƿ�Ϊ��: " << (ivec.empty() ? "��" : "��") << std::endl; // ���: ��
        std::cout << "���� size()" << std::endl;
        std::cout << "IntVector ��С: " << ivec.size() << std::endl; // ���: 3
        std::cout << "���� get_capacity()" << std::endl;
        std::cout << "IntVector ����: " << ivec.get_capacity() << std::endl; // ���: 3

        // ���� at()
        std::cout << "���� at(1)" << std::endl;
        std::cout << "Ԫ�� at index 1: " << ivec.at(1) << std::endl; // ���: 20

        // ����Խ�����
        std::cout << "���� at(3) ��ͼ����Խ������" << std::endl;
        std::cout << ivec.at(3) << std::endl; // Ӧ�׳��쳣
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << "\n" << std::endl;
    }

    pause(); // ��ͣ���ȴ��û�ȷ��

    try {
        // ���� pop()
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl; // ���: 30
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl; // ���: 20
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl; // ���: 10

        // �ӿ������е���Ԫ��
        std::cout << "���� pop() �ӿ� IntVector �е���Ԫ��" << std::endl;
        std::cout << "���Դӿ� IntVector �� Pop: " << ivec.pop() << std::endl; // Ӧ�׳��쳣
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << "\n" << std::endl;
    }

    pause(); // ��ͣ���ȴ��û�ȷ��

    // 2. ���� DoubleVector
    std::cout << "=== ���� DoubleVector ===" << std::endl;
    DoubleVector dvec;
    try {
        std::cout << "���� push() ���Ԫ�� 1.1" << std::endl;
        dvec.push(1.1);
        std::cout << "���� push() ���Ԫ�� 2.2" << std::endl;
        dvec.push(2.2);
        std::cout << "���� push() ���Ԫ�� 3.3" << std::endl;
        dvec.push(3.3);
        std::cout << "��ʼ DoubleVector: " << dvec << std::endl; // ���: [ 1.1 2.2 3.3 ]

        // ���� empty() �� size()
        std::cout << "���� empty()" << std::endl;
        std::cout << "DoubleVector �Ƿ�Ϊ��: " << (dvec.empty() ? "��" : "��") << std::endl; // ���: ��
        std::cout << "���� size()" << std::endl;
        std::cout << "DoubleVector ��С: " << dvec.size() << std::endl; // ���: 3
        std::cout << "���� get_capacity()" << std::endl;
        std::cout << "DoubleVector ����: " << dvec.get_capacity() << std::endl; // ���: 3

        // ���� at()
        std::cout << "���� at(0)" << std::endl;
        std::cout << "Ԫ�� at index 0: " << dvec.at(0) << std::endl; // ���: 1.1

        // ����Խ�����
        std::cout << "���� at(3) ��ͼ����Խ������" << std::endl;
        std::cout << dvec.at(3) << std::endl; // Ӧ�׳��쳣
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << "\n" << std::endl;
    }

    pause(); // ��ͣ���ȴ��û�ȷ��

    try {
        // ���� pop()
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl; // ���: 3.3
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl; // ���: 2.2
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl; // ���: 1.1

        // �ӿ������е���Ԫ��
        std::cout << "���� pop() �ӿ� DoubleVector �е���Ԫ��" << std::endl;
        std::cout << "���Դӿ� DoubleVector �� Pop: " << dvec.pop() << std::endl; // Ӧ�׳��쳣
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << "\n" << std::endl;
    }

    pause(); // ��ͣ���ȴ��û�ȷ��

    // 3. ���� StringVector
    std::cout << "=== ���� StringVector ===" << std::endl;
    StringVector svec;
    try {
        std::cout << "���� push() ���Ԫ�� \"Manba\"" << std::endl;
        svec.push("Manba");
        std::cout << "���� push() ���Ԫ�� \" \"" << std::endl;
        svec.push(" ");
        std::cout << "���� push() ���Ԫ�� \"Out\"" << std::endl;
        svec.push("Out");
        std::cout << "���� push() ���Ԫ�� \"!\"" << std::endl;
        svec.push("!");
        std::cout << "��ʼ StringVector: " << svec << std::endl; // ���: [ "Hello" " " "World" "!" ]

        // ���� empty() �� size()
        std::cout << "���� empty()" << std::endl;
        std::cout << "StringVector �Ƿ�Ϊ��: " << (svec.empty() ? "��" : "��") << std::endl; // ���: ��
        std::cout << "���� size()" << std::endl;
        std::cout << "StringVector ��С: " << svec.size() << std::endl; // ���: 4
        std::cout << "���� get_capacity()" << std::endl;
        std::cout << "StringVector ����: " << svec.get_capacity() << std::endl; // ���: 4

        // ���� concatenate()
        std::cout << "���� concatenate()" << std::endl;
        std::cout << "ƴ�Ӻ���ַ���: " << svec.concatenate() << std::endl; // ���: Hello World!

        // ���� at()
        std::cout << "���� at(1)" << std::endl;
        std::cout << "Ԫ�� at index 1: \"" << svec.at(1) << "\"" << std::endl; // ���: " "

        // ����Խ�����
        std::cout << "���� at(4) ��ͼ����Խ������" << std::endl;
        std::cout << "���Է��� index 4: \"" << svec.at(4) << "\"" << std::endl; // Ӧ�׳��쳣
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << "\n" << std::endl;
    }

    pause(); // ��ͣ���ȴ��û�ȷ��

    try {
        // ���� pop()
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl; // ���: "!"
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl; // ���: "World"
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl; // ���: " "
        std::cout << "���� pop() �Ƴ����������һ��Ԫ��" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl; // ���: "Hello"

        // �ӿ������е���Ԫ��
        std::cout << "���� pop() �ӿ� StringVector �е���Ԫ��" << std::endl;
        std::cout << "���Դӿ� StringVector �� Pop: \"" << svec.pop() << "\"" << std::endl; // Ӧ�׳��쳣
    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << "\n" << std::endl;
    }

    pause(); // ��ͣ���ȴ��û�ȷ��

    // 4. ������������أ�operator+ �� operator+=
    std::cout << "=== ������������� ===" << std::endl;

    // ���� IntVector �� operator+
    std::cout << "���� operator+ �� ivec1 �� ivec2 ���" << std::endl;
    IntVector ivec1;
    std::cout << "���� push() �� ivec1 ���Ԫ�� 1" << std::endl;
    ivec1.push(1);
    std::cout << "���� push() �� ivec1 ���Ԫ�� 2" << std::endl;
    ivec1.push(2);

    IntVector ivec2;
    std::cout << "���� push() �� ivec2 ���Ԫ�� 3" << std::endl;
    ivec2.push(3);
    std::cout << "���� push() �� ivec2 ���Ԫ�� 4" << std::endl;
    ivec2.push(4);

    std::cout << "��ǰ ivec1: " << ivec1 << std::endl;
    std::cout << "��ǰ ivec2: " << ivec2 << std::endl;

    IntVector ivec3 = ivec1 + ivec2; // ���� operator+
    std::cout << "ivec1 + ivec2: " << ivec3 << std::endl; // ���: [ 1 2 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� IntVector �� operator+=
    std::cout << "���� operator+= �� ivec2 ׷�ӵ� ivec1 ��" << std::endl;
    ivec1 += ivec2; // ���� operator+=
    std::cout << "ivec1 += ivec2: " << ivec1 << std::endl; // ���: [ 1 2 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� DoubleVector �� operator+
    std::cout << "���� operator+ �� dvec1 �� dvec2 ���" << std::endl;
    DoubleVector dvec1;
    std::cout << "���� push() �� dvec1 ���Ԫ�� 1.1" << std::endl;
    dvec1.push(1.1);
    std::cout << "���� push() �� dvec1 ���Ԫ�� 2.2" << std::endl;
    dvec1.push(2.2);

    DoubleVector dvec2;
    std::cout << "���� push() �� dvec2 ���Ԫ�� 3.3" << std::endl;
    dvec2.push(3.3);
    std::cout << "���� push() �� dvec2 ���Ԫ�� 4.4" << std::endl;
    dvec2.push(4.4);

    std::cout << "��ǰ dvec1: " << dvec1 << std::endl;
    std::cout << "��ǰ dvec2: " << dvec2 << std::endl;

    DoubleVector dvec3 = dvec1 + dvec2;
    std::cout << "dvec1 + dvec2: " << dvec3 << std::endl; // ���: [ 1.1 2.2 3.3 4.4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� DoubleVector �� operator+=
    std::cout << "���� operator+= �� dvec2 ׷�ӵ� dvec1 ��" << std::endl;
    dvec1 += dvec2;
    std::cout << "dvec1 += dvec2: " << dvec1 << std::endl; // ���: [ 1.1 2.2 3.3 4.4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� StringVector �� operator+
    std::cout << "���� operator+ �� svec1 �� svec2 ���" << std::endl;
    StringVector svec1;
    std::cout << "���� push() �� svec1 ���Ԫ�� \"What \"" << std::endl;
    svec1.push("What ");
    std::cout << "���� push() �� svec1 ���Ԫ�� \"can \"" << std::endl;
    svec1.push("can ");
    std::cout << "���� push() �� svec1 ���Ԫ�� \"I \"" << std::endl;
    svec1.push("I ");

    StringVector svec2;
    std::cout << "���� push() �� svec2 ���Ԫ�� \"say \"" << std::endl;
    svec2.push("say ");
    std::cout << "���� push() �� svec2 ���Ԫ�� \"Manba out! \"" << std::endl;
    svec2.push("Manba out! ");

    std::cout << "��ǰ svec1: " << svec1 << std::endl;
    std::cout << "��ǰ svec2: " << svec2 << std::endl;

    StringVector svec3 = svec1 + svec2;
    std::cout << "svec1 + svec2: " << svec3 << std::endl; // ���: [ "Good" " " "Morning" "!" " Have a great day." ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� StringVector �� operator+=
    std::cout << "���� operator+= �� svec2 ׷�ӵ� svec1 ��" << std::endl;
    svec1 += svec2;
    std::cout << "svec1 += svec2: " << svec1 << std::endl; // ���: [ "Good" " " "Morning" "!" " Have a great day." ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    std::cout << "\n" << std::endl;

    // 5. ���Ը߼����ܣ�reserve(), shrink_to_fit(), insert(), erase(), swap()
    std::cout << "=== ���Ը߼����� ===" << std::endl;

    // ���� reserve() �� get_capacity()
    std::cout << "���� reserve(10) Ԥ�� ivec1 �������� 10" << std::endl;
    ivec1.reserve(10);
    std::cout << "ivec1 ����Ԥ���� 10: " << ivec1.get_capacity() << std::endl; // ���: 10
    std::cout << "���� size()" << std::endl;
    std::cout << "ivec1 ��С: " << ivec1.size() << std::endl; // ���: 4
    std::cout << "��ǰ ivec1: " << ivec1 << std::endl; // ���: [ 1 2 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� shrink_to_fit()
    std::cout << "\n���� shrink_to_fit() ���� ivec1 ���������ʺϴ�С" << std::endl;
    ivec1.shrink_to_fit();
    std::cout << "ivec1 �����������ʺϴ�С: " << ivec1.get_capacity() << std::endl; // ���: 4
    std::cout << "��ǰ ivec1: " << ivec1 << std::endl; // ���: [ 1 2 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� insert()
    std::cout << "\n���� insert(2, 99) ������ 2 ���� 99" << std::endl;
    ivec1.insert(2, 99); // ������ 2 ���� 99
    std::cout << "ivec1 ���� 99 ������ 2: " << ivec1 << std::endl; // ���: [ 1 2 99 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    std::cout << "���� insert(1, 2, 55) ������ 1 �������� 55" << std::endl;
    ivec1.insert(1, 2, 55); // ������ 1 �������� 55
    std::cout << "ivec1 �������� 55 ������ 1: " << ivec1 << std::endl; // ���: [ 1 55 55 2 99 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� erase()
    std::cout << "\n���� erase(3) ɾ������ 3 ��Ԫ�� (2)" << std::endl;
    ivec1.erase(3); // ɾ������ 3 ��Ԫ�� (2)
    std::cout << "ivec1 ɾ������ 3 ��Ԫ��: " << ivec1 << std::endl; // ���: [ 1 55 55 99 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    std::cout << "���� erase(1, 2) ɾ������ 1 �� 2 ��Ԫ�� (55, 55)" << std::endl;
    ivec1.erase(1, 2); // ɾ������ 1 �� 2 ��Ԫ�� (55, 55)
    std::cout << "ivec1 ɾ������ 1 �� 2 ��Ԫ��: " << ivec1 << std::endl; // ���: [ 1 99 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���� swap()
    std::cout << "\n���� swap() ���� ivec1 �� ivec_swap ������" << std::endl;
    IntVector ivec_swap;
    std::cout << "���� push() �� ivec_swap ���Ԫ�� 100" << std::endl;
    ivec_swap.push(100);
    std::cout << "���� push() �� ivec_swap ���Ԫ�� 200" << std::endl;
    ivec_swap.push(200);
    std::cout << "ivec_swap ��ʼ: " << ivec_swap << std::endl; // ���: [ 100 200 ]

    std::cout << "ivec1 ��ʼ: " << ivec1 << std::endl; // ���: [ 1 99 3 4 ]

    ivec1.swap(ivec_swap);
    std::cout << "������ ivec1: " << ivec1 << std::endl; // ���: [ 100 200 ]
    std::cout << "������ ivec_swap: " << ivec_swap << std::endl; // ���: [ 1 99 3 4 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    std::cout << "\n" << std::endl;

    // 6. ������������أ�operator++ (ǰ�úͺ���)
    std::cout << "=== ���Ե�������� ===" << std::endl;
    IntVector ivec_inc;
    std::cout << "���� push() �� ivec_inc ���Ԫ�� 5" << std::endl;
    ivec_inc.push(5);
    std::cout << "���� push() �� ivec_inc ���Ԫ�� 10" << std::endl;
    ivec_inc.push(10);
    std::cout << "���� push() �� ivec_inc ���Ԫ�� 15" << std::endl;
    ivec_inc.push(15);
    std::cout << "��ʼ ivec_inc: " << ivec_inc << std::endl; // ���: [ 5 10 15 ]

    // ǰ�õ���
    std::cout << "����ǰ�õ�������� ++ivec_inc" << std::endl;
    ++ivec_inc;
    std::cout << "++ivec_inc: " << ivec_inc << std::endl; // ���: [ 6 11 16 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���õ���
    std::cout << "���ú��õ�������� ivec_before = ivec_inc++" << std::endl;
    IntVector ivec_before = ivec_inc++;
    std::cout << "ivec_before = ivec_inc++: " << ivec_before << std::endl; // ���: [ 6 11 16 ]
    std::cout << "ivec_inc ֮��: " << ivec_inc << std::endl;               // ���: [ 7 12 17 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ͬ������ DoubleVector
    DoubleVector dvec_inc;
    std::cout << "���� push() �� dvec_inc ���Ԫ�� 2.5" << std::endl;
    dvec_inc.push(2.5);
    std::cout << "���� push() �� dvec_inc ���Ԫ�� 5.5" << std::endl;
    dvec_inc.push(5.5);
    std::cout << "���� push() �� dvec_inc ���Ԫ�� 8.5" << std::endl;
    dvec_inc.push(8.5);
    std::cout << "��ʼ dvec_inc: " << dvec_inc << std::endl; // ���: [ 2.5 5.5 8.5 ]

    // ǰ�õ���
    std::cout << "����ǰ�õ�������� ++dvec_inc" << std::endl;
    ++dvec_inc;
    std::cout << "++dvec_inc: " << dvec_inc << std::endl; // ���: [ 3.5 6.5 9.5 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    // ���õ���
    std::cout << "���ú��õ�������� dvec_before = dvec_inc++" << std::endl;
    DoubleVector dvec_before = dvec_inc++;
    std::cout << "dvec_before = dvec_inc++: " << dvec_before << std::endl; // ���: [ 3.5 6.5 9.5 ]
    std::cout << "dvec_inc ֮��: " << dvec_inc << std::endl;               // ���: [ 4.5 7.5 10.5 ]

    pause(); // ��ͣ���ȴ��û�ȷ��

    std::cout << "\n" << std::endl;

    // 7. ���Զ�̬��̬��
    std::cout << "=== ���Զ�̬��̬�� ===" << std::endl;

    // ����ָ��ָ�����������
    Vector<int>* baseIntPtr = new IntVector();
    Vector<double>* baseDoublePtr = new DoubleVector();
    Vector<std::string>* baseStringPtr = new StringVector();

    try {
        // ���� IntVector ͨ������ָ��
        std::cout << "���� push() �� baseIntPtr ָ��� IntVector ���Ԫ�� 100" << std::endl;
        baseIntPtr->push(100);
        std::cout << "���� push() �� baseIntPtr ָ��� IntVector ���Ԫ�� 200" << std::endl;
        baseIntPtr->push(200);
        std::cout << "���� push() �� baseIntPtr ָ��� IntVector ���Ԫ�� 300" << std::endl;
        baseIntPtr->push(300);
        std::cout << "IntVector via Vector<int>*: " << *baseIntPtr << std::endl; // ���: [ 100 200 300 ]

        pause(); // ��ͣ���ȴ��û�ȷ��

        // ���� DoubleVector ͨ������ָ��
        std::cout << "���� push() �� baseDoublePtr ָ��� DoubleVector ���Ԫ�� 4.4" << std::endl;
        baseDoublePtr->push(4.4);
        std::cout << "���� push() �� baseDoublePtr ָ��� DoubleVector ���Ԫ�� 5.5" << std::endl;
        baseDoublePtr->push(5.5);
        std::cout << "���� push() �� baseDoublePtr ָ��� DoubleVector ���Ԫ�� 6.6" << std::endl;
        baseDoublePtr->push(6.6);
        std::cout << "DoubleVector via Vector<double>*: " << *baseDoublePtr << std::endl; // ���: [ 4.4 5.5 6.6 ]

        pause(); // ��ͣ���ȴ��û�ȷ��

        // ���� StringVector ͨ������ָ��
        std::cout << "���� push() �� baseStringPtr ָ��� StringVector ���Ԫ�� \"��\"" << std::endl;
        baseStringPtr->push("��");
        std::cout << "���� push() �� baseStringPtr ָ��� StringVector ���Ԫ�� \"��\"" << std::endl;
        baseStringPtr->push("��");
        std::cout << "���� push() �� baseStringPtr ָ��� StringVector ���Ԫ�� \"̥\"" << std::endl;
        baseStringPtr->push("̥");
        std::cout << "���� push() �� baseStringPtr ָ��� StringVector ���Ԫ�� \"ú\"" << std::endl;
        baseStringPtr->push("ú");
        std::cout << "StringVector via Vector<std::string>*: " << *baseStringPtr << std::endl; // ���: [ "Dynamic" " " "Polymorphism" "!" ]

        pause(); // ��ͣ���ȴ��û�ȷ��

        // ���Ե��������ͨ������ָ��
        std::cout << "����ǰ�õ�������� ++(*specificIntPtr)" << std::endl;
        // ������ָ��ת��Ϊ��������ָ��
        IntVector* specificIntPtr = dynamic_cast<IntVector*>(baseIntPtr);
        if (specificIntPtr) {
            ++(*specificIntPtr);
            std::cout << "++(*baseIntPtr): " << *baseIntPtr << std::endl; // ���: [ 101 201 301 ]
        }
        else {
            std::cerr << "ת��ʧ��: baseIntPtr ���� IntVector ���͡�" << std::endl;
        }

        pause(); // ��ͣ���ȴ��û�ȷ��

        // ���� concatenate() ͨ������ָ��
        std::cout << "���� concatenate() ͨ�� baseStringPtr ָ��� StringVector" << std::endl;
        StringVector* specificStringPtr = dynamic_cast<StringVector*>(baseStringPtr);
        if (specificStringPtr) {
            std::cout << "ƴ�Ӻ���ַ��� via Vector<std::string>*: " << specificStringPtr->concatenate() << std::endl; // ���: Dynamic Polymorphism!
        }
        else {
            std::cerr << "ת��ʧ��: baseStringPtr ���� StringVector ���͡�" << std::endl;
        }

        pause(); // ��ͣ���ȴ��û�ȷ��

        // ���� reserve() ͨ������ָ��
        std::cout << "���� reserve(10) ͨ�� baseDoublePtr ָ��� DoubleVector" << std::endl;
        baseDoublePtr->reserve(10);
        std::cout << "DoubleVector Ԥ�������� 10: " << baseDoublePtr->get_capacity() << std::endl; // ���: 10
        std::cout << "���� size() ͨ�� baseDoublePtr ָ��� DoubleVector" << std::endl;
        std::cout << "DoubleVector ��С: " << baseDoublePtr->size() << std::endl; // ���: 3

        pause(); // ��ͣ���ȴ��û�ȷ��

        // ���� insert() ͨ������ָ��
        std::cout << "���� insert(1, 150) ͨ�� baseIntPtr ָ��� IntVector" << std::endl;
        if (specificIntPtr) {
            specificIntPtr->insert(1, 150); // ������ 1 ���� 150
            std::cout << "IntVector ���� 150 ������ 1: " << *baseIntPtr << std::endl; // ���: [ 101 150 201 301 ]
        }
        else {
            std::cerr << "ת��ʧ��: baseIntPtr ���� IntVector ���͡�" << std::endl;
        }

        pause(); // ��ͣ���ȴ��û�ȷ��

        // ���� erase() ͨ������ָ��
        std::cout << "���� erase(2) ͨ�� baseIntPtr ָ��� IntVector" << std::endl;
        if (specificIntPtr) {
            specificIntPtr->erase(2); // ɾ������ 2 ��Ԫ�� (201)
            std::cout << "IntVector ɾ������ 2 ��Ԫ��: " << *baseIntPtr << std::endl; // ���: [ 101 150 301 ]
        }
        else {
            std::cerr << "ת��ʧ��: baseIntPtr ���� IntVector ���͡�" << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "�쳣����: " << e.what() << "\n" << std::endl;
    }

    // ����
    delete baseIntPtr;
    delete baseDoublePtr;
    delete baseStringPtr;

    std::cout << "\n=== ���Խ��� ===" << std::endl;
    return 0;
}

// ���� pause �������ȴ��û����»س�������
void pause() {
    std::cout << "�����������..." << std::endl;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << "----------------------------------------\n" << std::endl;
}
