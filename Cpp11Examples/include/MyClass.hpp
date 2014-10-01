#ifndef MYCLASS_HPP_
#define MYCLASS_HPP_

#include <stdafx.h>

class MyClass {

private:
    int _int { 0 };
    std::string _string { "initialized" };

public:
    MyClass() = default;

    MyClass(int i) : _int{i} {
    }

    MyClass(int i, const std::string& s) : _int { i }, _string { s } {
    }

    std::string str() const {
        return std::to_string(_int) + ", " + _string;
    }

    static void MyClassExample() {
        MyClass m1;
        std::cout << m1.str() << std::endl;
        MyClass m2 { 7 };
        std::cout << m2.str() << std::endl;
        MyClass m3 { 7, "foo" };
        std::cout << m3.str() << std::endl;
    }
};

#endif /* MYCLASS_HPP_ */
