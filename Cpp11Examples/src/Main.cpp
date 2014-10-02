#include <stdafx.h>

#include <Timer.hpp>
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

    std::random_device rd;
    std::default_random_engine generator { rd() };
    std::uniform_int_distribution<uint64_t> distribution;


    Timer t0;
    std::vector<std::set<uint64_t>> v;
    for(size_t i = 0; i < 50000; ++i) {
        std::set<uint64_t> set;
        for(size_t j = 0; j < 1200; ++j) {
            auto random_number = distribution(generator);
            set.insert(random_number);
        }
        v.push_back(set);
    }
    Timer t1;
    std::cout << "(construction) t1 elapsed=" << Timer::Elapsed(t0,t1) << std::endl;

    std::sort(v.begin(), v.end());
    Timer t2;
    std::cout << "(sort) t2 elapsed=" << Timer::Elapsed(t1,t2) << std::endl;


    std::rotate(v.begin(), (v.begin() + (v.size()/2)), v.end());
    Timer t3;
    std::cout << "(rotate) t3 elapsed=" << Timer::Elapsed(t2,t3) << std::endl;

    std::cout << "total elapsed= " << Timer::Elapsed(t0,t3) << std::endl;

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

void OtherFeaturesExamples() {

    std::vector<std::map<std::string, uint64_t>> v { { { "key1", 17 }, { "key2", 23 } } };

    std::vector<std::map<std::string, uint64_t>>::const_iterator cit1 = v.cbegin();
    const std::map<std::string, uint64_t>& m1 = (*cit1);

    auto cit2 = v.cbegin();
    auto& m2 = (*cit2);

    // Error: m2.insert(std::make_pair("key3", 91 ));

    std::cout << "m1=" << *m1.begin() << std::endl;
    std::cout << "m2=" << *m2.begin() << std::endl;

    std::cout << std::endl << std::make_pair("p", 2) << std::endl;

    std::array<int, 4> firstIntArray { { 1, 2, 3, 4 } };
    std::cout << ContainerToString(firstIntArray) << std::endl;

    std::vector<std::shared_ptr<std::string>> right_angle_bracket;
    std::cout << ContainerToString(right_angle_bracket) << std::endl;
}

using namespace std;

pair<string, string::size_type> createEntry(const string& s) {
    return {s, s.length()};
}

void InitializationSyntaxExample() {
    string str1 { "test" };
    int v1 { 4 };
    map<string, string::size_type> map1 { { str1, v1 }, { "key1", 3 }, { "a", 1 } };
    map1.insert(createEntry("modern"));
    std::cout << ContainerToString(map1, ",\n") << std::endl;
}

void RangeBasedLoopExample() {
    const std::vector<std::complex<double>> cvector { {2, 3}, {4, 5} };
    {
        std::complex<double> r1 { 1, 0 };
        for (std::vector<std::complex<double>>::const_iterator cit = cvector.begin();
                cit != cvector.end(); ++cit) {
            const std::complex<double>& c = (*cit);
            r1 *= c;
        }
        std::cout << "r1=" << r1 << std::endl;
    }
    {
        std::complex<double> r2 { 1, 0 };
        for (const auto& c : cvector) {
            r2 *= c;
        }
        std::cout << "r2=" << r2 << std::endl;
    }
}

int main() {

    INVOKE_METHOD(OtherFeaturesExamples());

    INVOKE_METHOD(SmartPointersExample());

    INVOKE_METHOD(ToStringExample());

    INVOKE_METHOD(ArraysExamples());

    INVOKE_METHOD(MyClass::MyClassExample());

    INVOKE_METHOD(ReturnValueOptimizationExample::Execute());

    INVOKE_METHOD(PerformanceTest());

    INVOKE_METHOD(InitializationSyntaxExample());

    INVOKE_METHOD(RangeBasedLoopExample());

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

