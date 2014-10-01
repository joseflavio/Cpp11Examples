#include <stdafx.h>

#include <PrintUtils.hpp>
#include <ExamplesHeader.hpp>

#include <MyInteger.hpp>
#include <MyClass.hpp>


enum class ExchangePolicy {
    NoExchange, ExchangePerBookedTrip
};

enum class Color {
    Red, Blue
};

void nullptrTypeExample() {
#ifdef SHOW_ERRORS
    const int p = 0;
    if (p == nullptr) {
        throw std::exception();
    }
#endif
}

void ArraysExamples() {
    {
        std::array<std::string, 3> a { { "foo", "baz", "bar" } };
        std::sort(a.begin(), a.end());
        for (const auto& v : a) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::array<int, 5> a { { 1, 2, 3, 4, 5 } };
        std::reverse(a.begin(), a.end());
        for (const auto& v : a) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }
}

bool StronglyTypedEnumTest() {
    ExchangePolicy a { ExchangePolicy::ExchangePerBookedTrip };
    // Valid
    if (a == ExchangePolicy::NoExchange) {
        return true;
    }
#ifdef SHOW_ERRORS
    // Error
    if ( a == Color::Red ) {
        return true;
    }
    // Error
    if ( a == 0 ) {
        return true;
    }
#endif
    return false;
}

void PerformanceTest() {
    time_t start = time(NULL);
    // sleep(3);
    time_t end = time(NULL);
    std::cout << "elapsed: " << (end - start) << std::endl;

}

void SmartPointersExample() {
    std::shared_ptr<int64_t> sp1 { new int64_t { 8 } };
    if (sp1 == nullptr) {
        throw std::exception();
    }
    std::cout << "sp1=" << sp1 << std::endl;

    std::shared_ptr<MyInteger> sp2 { new MyInteger { 6 } };
    if (sp2 == nullptr) {
        throw std::exception();
    }
    std::cout << "sp2=" << sp2 << std::endl;
    sp2 = nullptr;
    std::cout << "sp2=" << sp2 << std::endl;
}

void ToStringExample() {
    std::random_device rd;
    std::default_random_engine generator { rd() };
    std::uniform_int_distribution<int8_t> distribution(1, 6);
    for (int i = 0; i < 5; ++i) {
        auto dice_roll = distribution(generator);
        std::cout << "roll #" << i << ": ";
        std::cout << std::to_string(dice_roll) << std::endl;
    }
}

int main() {

    INVOKE_METHOD(SmartPointersExample());

    INVOKE_METHOD(ToStringExample());

    INVOKE_METHOD(ArraysExamples());

    INVOKE_METHOD(MyClass::MyClassExample());

    INVOKE_METHOD(ReturnValueOptimizationExample::Execute());

    INVOKE_METHOD(PerformanceTest());

    /*
     * Other features
     */

    std::cout << std::endl << std::make_pair("p", 2) << std::endl;

    std::array<int, 4> firstIntArray { { 1, 2, 3, 4 } };
    std::cout << ContainerToString(firstIntArray) << std::endl;

    std::vector<std::shared_ptr<std::string>> right_angle_bracket;
    std::cout << ContainerToString(right_angle_bracket) << std::endl;

    return 0;

}

using namespace std;

char rot13(const char c) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 13) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + 13) % 26 + 'A';
    }
    return c;
}

string &convertLine(string &s) {
    for (auto &c : s) {
        c = rot13(c);
    }
    return s;
}

void readLines(istream &in, ostream &out) {
    string s;
    while (getline(in, s)) {
        out << convertLine(s) << '\n';
    }
}

int main2(int argc, char *argv[]) {
    if (argc == 1) {
        readLines(cin, cout);
    } else {
        for (int arg = 1; arg < argc; ++arg) {
            ifstream fs { argv[arg] };
            if (!fs) {
                return EXIT_FAILURE;
            }
            readLines(fs, cout);
        }
    }
    return EXIT_SUCCESS;
}

