// main.cpp
#include <iostream>
#include "NumericVector.h"
#include "StringVector.h"

// 函数声明，用于在测试部分之间添加暂停
void pause();

int main() {
    std::cout << "=== 综合测试程序 ===\n" << std::endl;

    // 1. 测试 IntVector
    std::cout << "=== 测试 IntVector ===" << std::endl;
    IntVector ivec;
    try {
        std::cout << "调用 push() 添加元素 11" << std::endl;
        ivec.push(11);
        std::cout << "调用 push() 添加元素 45" << std::endl;
        ivec.push(45);
        std::cout << "调用 push() 添加元素 14" << std::endl;
        ivec.push(14);
        std::cout << "初始 IntVector: " << ivec << std::endl; // 输出: [ 10 20 30 ]

        // 测试 empty() 和 size()
        std::cout << "调用 empty()" << std::endl;
        std::cout << "IntVector 是否为空: " << (ivec.empty() ? "是" : "否") << std::endl; // 输出: 否
        std::cout << "调用 size()" << std::endl;
        std::cout << "IntVector 大小: " << ivec.size() << std::endl; // 输出: 3
        std::cout << "调用 get_capacity()" << std::endl;
        std::cout << "IntVector 容量: " << ivec.get_capacity() << std::endl; // 输出: 3

        // 测试 at()
        std::cout << "调用 at(1)" << std::endl;
        std::cout << "元素 at index 1: " << ivec.at(1) << std::endl; // 输出: 20

        // 测试越界访问
        std::cout << "调用 at(3) 试图访问越界索引" << std::endl;
        std::cout << ivec.at(3) << std::endl; // 应抛出异常
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << "\n" << std::endl;
    }

    pause(); // 暂停，等待用户确认

    try {
        // 测试 pop()
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl; // 输出: 30
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl; // 输出: 20
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: " << ivec.pop() << std::endl; // 输出: 10

        // 从空向量中弹出元素
        std::cout << "调用 pop() 从空 IntVector 中弹出元素" << std::endl;
        std::cout << "尝试从空 IntVector 中 Pop: " << ivec.pop() << std::endl; // 应抛出异常
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << "\n" << std::endl;
    }

    pause(); // 暂停，等待用户确认

    // 2. 测试 DoubleVector
    std::cout << "=== 测试 DoubleVector ===" << std::endl;
    DoubleVector dvec;
    try {
        std::cout << "调用 push() 添加元素 1.1" << std::endl;
        dvec.push(1.1);
        std::cout << "调用 push() 添加元素 2.2" << std::endl;
        dvec.push(2.2);
        std::cout << "调用 push() 添加元素 3.3" << std::endl;
        dvec.push(3.3);
        std::cout << "初始 DoubleVector: " << dvec << std::endl; // 输出: [ 1.1 2.2 3.3 ]

        // 测试 empty() 和 size()
        std::cout << "调用 empty()" << std::endl;
        std::cout << "DoubleVector 是否为空: " << (dvec.empty() ? "是" : "否") << std::endl; // 输出: 否
        std::cout << "调用 size()" << std::endl;
        std::cout << "DoubleVector 大小: " << dvec.size() << std::endl; // 输出: 3
        std::cout << "调用 get_capacity()" << std::endl;
        std::cout << "DoubleVector 容量: " << dvec.get_capacity() << std::endl; // 输出: 3

        // 测试 at()
        std::cout << "调用 at(0)" << std::endl;
        std::cout << "元素 at index 0: " << dvec.at(0) << std::endl; // 输出: 1.1

        // 测试越界访问
        std::cout << "调用 at(3) 试图访问越界索引" << std::endl;
        std::cout << dvec.at(3) << std::endl; // 应抛出异常
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << "\n" << std::endl;
    }

    pause(); // 暂停，等待用户确认

    try {
        // 测试 pop()
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl; // 输出: 3.3
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl; // 输出: 2.2
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: " << dvec.pop() << std::endl; // 输出: 1.1

        // 从空向量中弹出元素
        std::cout << "调用 pop() 从空 DoubleVector 中弹出元素" << std::endl;
        std::cout << "尝试从空 DoubleVector 中 Pop: " << dvec.pop() << std::endl; // 应抛出异常
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << "\n" << std::endl;
    }

    pause(); // 暂停，等待用户确认

    // 3. 测试 StringVector
    std::cout << "=== 测试 StringVector ===" << std::endl;
    StringVector svec;
    try {
        std::cout << "调用 push() 添加元素 \"Manba\"" << std::endl;
        svec.push("Manba");
        std::cout << "调用 push() 添加元素 \" \"" << std::endl;
        svec.push(" ");
        std::cout << "调用 push() 添加元素 \"Out\"" << std::endl;
        svec.push("Out");
        std::cout << "调用 push() 添加元素 \"!\"" << std::endl;
        svec.push("!");
        std::cout << "初始 StringVector: " << svec << std::endl; // 输出: [ "Hello" " " "World" "!" ]

        // 测试 empty() 和 size()
        std::cout << "调用 empty()" << std::endl;
        std::cout << "StringVector 是否为空: " << (svec.empty() ? "是" : "否") << std::endl; // 输出: 否
        std::cout << "调用 size()" << std::endl;
        std::cout << "StringVector 大小: " << svec.size() << std::endl; // 输出: 4
        std::cout << "调用 get_capacity()" << std::endl;
        std::cout << "StringVector 容量: " << svec.get_capacity() << std::endl; // 输出: 4

        // 测试 concatenate()
        std::cout << "调用 concatenate()" << std::endl;
        std::cout << "拼接后的字符串: " << svec.concatenate() << std::endl; // 输出: Hello World!

        // 测试 at()
        std::cout << "调用 at(1)" << std::endl;
        std::cout << "元素 at index 1: \"" << svec.at(1) << "\"" << std::endl; // 输出: " "

        // 测试越界访问
        std::cout << "调用 at(4) 试图访问越界索引" << std::endl;
        std::cout << "尝试访问 index 4: \"" << svec.at(4) << "\"" << std::endl; // 应抛出异常
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << "\n" << std::endl;
    }

    pause(); // 暂停，等待用户确认

    try {
        // 测试 pop()
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl; // 输出: "!"
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl; // 输出: "World"
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl; // 输出: " "
        std::cout << "调用 pop() 移除并返回最后一个元素" << std::endl;
        std::cout << "Pop: \"" << svec.pop() << "\"" << std::endl; // 输出: "Hello"

        // 从空向量中弹出元素
        std::cout << "调用 pop() 从空 StringVector 中弹出元素" << std::endl;
        std::cout << "尝试从空 StringVector 中 Pop: \"" << svec.pop() << "\"" << std::endl; // 应抛出异常
    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << "\n" << std::endl;
    }

    pause(); // 暂停，等待用户确认

    // 4. 测试运算符重载：operator+ 和 operator+=
    std::cout << "=== 测试运算符重载 ===" << std::endl;

    // 测试 IntVector 的 operator+
    std::cout << "调用 operator+ 将 ivec1 和 ivec2 相加" << std::endl;
    IntVector ivec1;
    std::cout << "调用 push() 向 ivec1 添加元素 1" << std::endl;
    ivec1.push(1);
    std::cout << "调用 push() 向 ivec1 添加元素 2" << std::endl;
    ivec1.push(2);

    IntVector ivec2;
    std::cout << "调用 push() 向 ivec2 添加元素 3" << std::endl;
    ivec2.push(3);
    std::cout << "调用 push() 向 ivec2 添加元素 4" << std::endl;
    ivec2.push(4);

    std::cout << "当前 ivec1: " << ivec1 << std::endl;
    std::cout << "当前 ivec2: " << ivec2 << std::endl;

    IntVector ivec3 = ivec1 + ivec2; // 测试 operator+
    std::cout << "ivec1 + ivec2: " << ivec3 << std::endl; // 输出: [ 1 2 3 4 ]

    pause(); // 暂停，等待用户确认

    // 测试 IntVector 的 operator+=
    std::cout << "调用 operator+= 将 ivec2 追加到 ivec1 中" << std::endl;
    ivec1 += ivec2; // 测试 operator+=
    std::cout << "ivec1 += ivec2: " << ivec1 << std::endl; // 输出: [ 1 2 3 4 ]

    pause(); // 暂停，等待用户确认

    // 测试 DoubleVector 的 operator+
    std::cout << "调用 operator+ 将 dvec1 和 dvec2 相加" << std::endl;
    DoubleVector dvec1;
    std::cout << "调用 push() 向 dvec1 添加元素 1.1" << std::endl;
    dvec1.push(1.1);
    std::cout << "调用 push() 向 dvec1 添加元素 2.2" << std::endl;
    dvec1.push(2.2);

    DoubleVector dvec2;
    std::cout << "调用 push() 向 dvec2 添加元素 3.3" << std::endl;
    dvec2.push(3.3);
    std::cout << "调用 push() 向 dvec2 添加元素 4.4" << std::endl;
    dvec2.push(4.4);

    std::cout << "当前 dvec1: " << dvec1 << std::endl;
    std::cout << "当前 dvec2: " << dvec2 << std::endl;

    DoubleVector dvec3 = dvec1 + dvec2;
    std::cout << "dvec1 + dvec2: " << dvec3 << std::endl; // 输出: [ 1.1 2.2 3.3 4.4 ]

    pause(); // 暂停，等待用户确认

    // 测试 DoubleVector 的 operator+=
    std::cout << "调用 operator+= 将 dvec2 追加到 dvec1 中" << std::endl;
    dvec1 += dvec2;
    std::cout << "dvec1 += dvec2: " << dvec1 << std::endl; // 输出: [ 1.1 2.2 3.3 4.4 ]

    pause(); // 暂停，等待用户确认

    // 测试 StringVector 的 operator+
    std::cout << "调用 operator+ 将 svec1 和 svec2 相加" << std::endl;
    StringVector svec1;
    std::cout << "调用 push() 向 svec1 添加元素 \"What \"" << std::endl;
    svec1.push("What ");
    std::cout << "调用 push() 向 svec1 添加元素 \"can \"" << std::endl;
    svec1.push("can ");
    std::cout << "调用 push() 向 svec1 添加元素 \"I \"" << std::endl;
    svec1.push("I ");

    StringVector svec2;
    std::cout << "调用 push() 向 svec2 添加元素 \"say \"" << std::endl;
    svec2.push("say ");
    std::cout << "调用 push() 向 svec2 添加元素 \"Manba out! \"" << std::endl;
    svec2.push("Manba out! ");

    std::cout << "当前 svec1: " << svec1 << std::endl;
    std::cout << "当前 svec2: " << svec2 << std::endl;

    StringVector svec3 = svec1 + svec2;
    std::cout << "svec1 + svec2: " << svec3 << std::endl; // 输出: [ "Good" " " "Morning" "!" " Have a great day." ]

    pause(); // 暂停，等待用户确认

    // 测试 StringVector 的 operator+=
    std::cout << "调用 operator+= 将 svec2 追加到 svec1 中" << std::endl;
    svec1 += svec2;
    std::cout << "svec1 += svec2: " << svec1 << std::endl; // 输出: [ "Good" " " "Morning" "!" " Have a great day." ]

    pause(); // 暂停，等待用户确认

    std::cout << "\n" << std::endl;

    // 5. 测试高级功能：reserve(), shrink_to_fit(), insert(), erase(), swap()
    std::cout << "=== 测试高级功能 ===" << std::endl;

    // 测试 reserve() 和 get_capacity()
    std::cout << "调用 reserve(10) 预留 ivec1 的容量至 10" << std::endl;
    ivec1.reserve(10);
    std::cout << "ivec1 容量预留至 10: " << ivec1.get_capacity() << std::endl; // 输出: 10
    std::cout << "调用 size()" << std::endl;
    std::cout << "ivec1 大小: " << ivec1.size() << std::endl; // 输出: 4
    std::cout << "当前 ivec1: " << ivec1 << std::endl; // 输出: [ 1 2 3 4 ]

    pause(); // 暂停，等待用户确认

    // 测试 shrink_to_fit()
    std::cout << "\n调用 shrink_to_fit() 缩减 ivec1 的容量至适合大小" << std::endl;
    ivec1.shrink_to_fit();
    std::cout << "ivec1 容量缩减至适合大小: " << ivec1.get_capacity() << std::endl; // 输出: 4
    std::cout << "当前 ivec1: " << ivec1 << std::endl; // 输出: [ 1 2 3 4 ]

    pause(); // 暂停，等待用户确认

    // 测试 insert()
    std::cout << "\n调用 insert(2, 99) 在索引 2 插入 99" << std::endl;
    ivec1.insert(2, 99); // 在索引 2 插入 99
    std::cout << "ivec1 插入 99 在索引 2: " << ivec1 << std::endl; // 输出: [ 1 2 99 3 4 ]

    pause(); // 暂停，等待用户确认

    std::cout << "调用 insert(1, 2, 55) 在索引 1 插入两个 55" << std::endl;
    ivec1.insert(1, 2, 55); // 在索引 1 插入两个 55
    std::cout << "ivec1 插入两个 55 在索引 1: " << ivec1 << std::endl; // 输出: [ 1 55 55 2 99 3 4 ]

    pause(); // 暂停，等待用户确认

    // 测试 erase()
    std::cout << "\n调用 erase(3) 删除索引 3 的元素 (2)" << std::endl;
    ivec1.erase(3); // 删除索引 3 的元素 (2)
    std::cout << "ivec1 删除索引 3 的元素: " << ivec1 << std::endl; // 输出: [ 1 55 55 99 3 4 ]

    pause(); // 暂停，等待用户确认

    std::cout << "调用 erase(1, 2) 删除索引 1 和 2 的元素 (55, 55)" << std::endl;
    ivec1.erase(1, 2); // 删除索引 1 和 2 的元素 (55, 55)
    std::cout << "ivec1 删除索引 1 和 2 的元素: " << ivec1 << std::endl; // 输出: [ 1 99 3 4 ]

    pause(); // 暂停，等待用户确认

    // 测试 swap()
    std::cout << "\n调用 swap() 交换 ivec1 和 ivec_swap 的内容" << std::endl;
    IntVector ivec_swap;
    std::cout << "调用 push() 向 ivec_swap 添加元素 100" << std::endl;
    ivec_swap.push(100);
    std::cout << "调用 push() 向 ivec_swap 添加元素 200" << std::endl;
    ivec_swap.push(200);
    std::cout << "ivec_swap 初始: " << ivec_swap << std::endl; // 输出: [ 100 200 ]

    std::cout << "ivec1 初始: " << ivec1 << std::endl; // 输出: [ 1 99 3 4 ]

    ivec1.swap(ivec_swap);
    std::cout << "交换后 ivec1: " << ivec1 << std::endl; // 输出: [ 100 200 ]
    std::cout << "交换后 ivec_swap: " << ivec_swap << std::endl; // 输出: [ 1 99 3 4 ]

    pause(); // 暂停，等待用户确认

    std::cout << "\n" << std::endl;

    // 6. 测试运算符重载：operator++ (前置和后置)
    std::cout << "=== 测试递增运算符 ===" << std::endl;
    IntVector ivec_inc;
    std::cout << "调用 push() 向 ivec_inc 添加元素 5" << std::endl;
    ivec_inc.push(5);
    std::cout << "调用 push() 向 ivec_inc 添加元素 10" << std::endl;
    ivec_inc.push(10);
    std::cout << "调用 push() 向 ivec_inc 添加元素 15" << std::endl;
    ivec_inc.push(15);
    std::cout << "初始 ivec_inc: " << ivec_inc << std::endl; // 输出: [ 5 10 15 ]

    // 前置递增
    std::cout << "调用前置递增运算符 ++ivec_inc" << std::endl;
    ++ivec_inc;
    std::cout << "++ivec_inc: " << ivec_inc << std::endl; // 输出: [ 6 11 16 ]

    pause(); // 暂停，等待用户确认

    // 后置递增
    std::cout << "调用后置递增运算符 ivec_before = ivec_inc++" << std::endl;
    IntVector ivec_before = ivec_inc++;
    std::cout << "ivec_before = ivec_inc++: " << ivec_before << std::endl; // 输出: [ 6 11 16 ]
    std::cout << "ivec_inc 之后: " << ivec_inc << std::endl;               // 输出: [ 7 12 17 ]

    pause(); // 暂停，等待用户确认

    // 同样测试 DoubleVector
    DoubleVector dvec_inc;
    std::cout << "调用 push() 向 dvec_inc 添加元素 2.5" << std::endl;
    dvec_inc.push(2.5);
    std::cout << "调用 push() 向 dvec_inc 添加元素 5.5" << std::endl;
    dvec_inc.push(5.5);
    std::cout << "调用 push() 向 dvec_inc 添加元素 8.5" << std::endl;
    dvec_inc.push(8.5);
    std::cout << "初始 dvec_inc: " << dvec_inc << std::endl; // 输出: [ 2.5 5.5 8.5 ]

    // 前置递增
    std::cout << "调用前置递增运算符 ++dvec_inc" << std::endl;
    ++dvec_inc;
    std::cout << "++dvec_inc: " << dvec_inc << std::endl; // 输出: [ 3.5 6.5 9.5 ]

    pause(); // 暂停，等待用户确认

    // 后置递增
    std::cout << "调用后置递增运算符 dvec_before = dvec_inc++" << std::endl;
    DoubleVector dvec_before = dvec_inc++;
    std::cout << "dvec_before = dvec_inc++: " << dvec_before << std::endl; // 输出: [ 3.5 6.5 9.5 ]
    std::cout << "dvec_inc 之后: " << dvec_inc << std::endl;               // 输出: [ 4.5 7.5 10.5 ]

    pause(); // 暂停，等待用户确认

    std::cout << "\n" << std::endl;

    // 7. 测试动态多态性
    std::cout << "=== 测试动态多态性 ===" << std::endl;

    // 基类指针指向派生类对象
    Vector<int>* baseIntPtr = new IntVector();
    Vector<double>* baseDoublePtr = new DoubleVector();
    Vector<std::string>* baseStringPtr = new StringVector();

    try {
        // 操作 IntVector 通过基类指针
        std::cout << "调用 push() 向 baseIntPtr 指向的 IntVector 添加元素 100" << std::endl;
        baseIntPtr->push(100);
        std::cout << "调用 push() 向 baseIntPtr 指向的 IntVector 添加元素 200" << std::endl;
        baseIntPtr->push(200);
        std::cout << "调用 push() 向 baseIntPtr 指向的 IntVector 添加元素 300" << std::endl;
        baseIntPtr->push(300);
        std::cout << "IntVector via Vector<int>*: " << *baseIntPtr << std::endl; // 输出: [ 100 200 300 ]

        pause(); // 暂停，等待用户确认

        // 操作 DoubleVector 通过基类指针
        std::cout << "调用 push() 向 baseDoublePtr 指向的 DoubleVector 添加元素 4.4" << std::endl;
        baseDoublePtr->push(4.4);
        std::cout << "调用 push() 向 baseDoublePtr 指向的 DoubleVector 添加元素 5.5" << std::endl;
        baseDoublePtr->push(5.5);
        std::cout << "调用 push() 向 baseDoublePtr 指向的 DoubleVector 添加元素 6.6" << std::endl;
        baseDoublePtr->push(6.6);
        std::cout << "DoubleVector via Vector<double>*: " << *baseDoublePtr << std::endl; // 输出: [ 4.4 5.5 6.6 ]

        pause(); // 暂停，等待用户确认

        // 操作 StringVector 通过基类指针
        std::cout << "调用 push() 向 baseStringPtr 指向的 StringVector 添加元素 \"级\"" << std::endl;
        baseStringPtr->push("级");
        std::cout << "调用 push() 向 baseStringPtr 指向的 StringVector 添加元素 \"泥\"" << std::endl;
        baseStringPtr->push("泥");
        std::cout << "调用 push() 向 baseStringPtr 指向的 StringVector 添加元素 \"胎\"" << std::endl;
        baseStringPtr->push("胎");
        std::cout << "调用 push() 向 baseStringPtr 指向的 StringVector 添加元素 \"煤\"" << std::endl;
        baseStringPtr->push("煤");
        std::cout << "StringVector via Vector<std::string>*: " << *baseStringPtr << std::endl; // 输出: [ "Dynamic" " " "Polymorphism" "!" ]

        pause(); // 暂停，等待用户确认

        // 测试递增运算符通过基类指针
        std::cout << "调用前置递增运算符 ++(*specificIntPtr)" << std::endl;
        // 将基类指针转换为具体类型指针
        IntVector* specificIntPtr = dynamic_cast<IntVector*>(baseIntPtr);
        if (specificIntPtr) {
            ++(*specificIntPtr);
            std::cout << "++(*baseIntPtr): " << *baseIntPtr << std::endl; // 输出: [ 101 201 301 ]
        }
        else {
            std::cerr << "转换失败: baseIntPtr 不是 IntVector 类型。" << std::endl;
        }

        pause(); // 暂停，等待用户确认

        // 测试 concatenate() 通过基类指针
        std::cout << "调用 concatenate() 通过 baseStringPtr 指向的 StringVector" << std::endl;
        StringVector* specificStringPtr = dynamic_cast<StringVector*>(baseStringPtr);
        if (specificStringPtr) {
            std::cout << "拼接后的字符串 via Vector<std::string>*: " << specificStringPtr->concatenate() << std::endl; // 输出: Dynamic Polymorphism!
        }
        else {
            std::cerr << "转换失败: baseStringPtr 不是 StringVector 类型。" << std::endl;
        }

        pause(); // 暂停，等待用户确认

        // 测试 reserve() 通过基类指针
        std::cout << "调用 reserve(10) 通过 baseDoublePtr 指向的 DoubleVector" << std::endl;
        baseDoublePtr->reserve(10);
        std::cout << "DoubleVector 预留容量至 10: " << baseDoublePtr->get_capacity() << std::endl; // 输出: 10
        std::cout << "调用 size() 通过 baseDoublePtr 指向的 DoubleVector" << std::endl;
        std::cout << "DoubleVector 大小: " << baseDoublePtr->size() << std::endl; // 输出: 3

        pause(); // 暂停，等待用户确认

        // 测试 insert() 通过基类指针
        std::cout << "调用 insert(1, 150) 通过 baseIntPtr 指向的 IntVector" << std::endl;
        if (specificIntPtr) {
            specificIntPtr->insert(1, 150); // 在索引 1 插入 150
            std::cout << "IntVector 插入 150 在索引 1: " << *baseIntPtr << std::endl; // 输出: [ 101 150 201 301 ]
        }
        else {
            std::cerr << "转换失败: baseIntPtr 不是 IntVector 类型。" << std::endl;
        }

        pause(); // 暂停，等待用户确认

        // 测试 erase() 通过基类指针
        std::cout << "调用 erase(2) 通过 baseIntPtr 指向的 IntVector" << std::endl;
        if (specificIntPtr) {
            specificIntPtr->erase(2); // 删除索引 2 的元素 (201)
            std::cout << "IntVector 删除索引 2 的元素: " << *baseIntPtr << std::endl; // 输出: [ 101 150 301 ]
        }
        else {
            std::cerr << "转换失败: baseIntPtr 不是 IntVector 类型。" << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "异常捕获: " << e.what() << "\n" << std::endl;
    }

    // 清理
    delete baseIntPtr;
    delete baseDoublePtr;
    delete baseStringPtr;

    std::cout << "\n=== 测试结束 ===" << std::endl;
    return 0;
}

// 定义 pause 函数，等待用户按下回车键继续
void pause() {
    std::cout << "按任意键继续..." << std::endl;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << "----------------------------------------\n" << std::endl;
}
