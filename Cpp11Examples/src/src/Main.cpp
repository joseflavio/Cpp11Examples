#include <stdafx.h>

#include <Timer.hpp>
#include <PrintUtils.hpp>
#include <ExamplesHeader.hpp>

#include <MyInteger.hpp>
#include <MyClass.hpp>

using std::cout;
using std::string;

enum class ExchangePolicy {
    NoExchange, ExchangePerBookedTrip
};

enum class Color {
    Red, Blue
};

void NullptrTypeExample() {
#ifdef SHOW_ERRORS
    const int p = 0;
    if (p == nullptr) {
        throw std::exception();
    }
#endif
}

void ArraysExamples() {
    {
        std::array<string, 3> a { { "foo", "baz", "bar" } };
        std::sort(a.begin(), a.end());
        for (const auto& v : a) {
            cout << v << ' ';
        }
        cout << "\n";
    }
    {
        std::array<int, 5> a { { 1, 2, 3, 4, 5 } };
        std::reverse(a.begin(), a.end());
        for (const auto& v : a) {
            cout << v << ' ';
        }
        cout << "\n";
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

void SmartPointersExample() {
    std::shared_ptr<int64_t> sp1 = std::make_shared<int64_t>(8);
    if (sp1 == nullptr) {
        throw std::exception();
    }
    cout << "sp1=" << sp1 << "\n";

    std::shared_ptr<MyInteger> sp2 = std::make_shared<MyInteger>(6);
    if (sp2 == nullptr) {
        throw std::exception();
    }
    cout << "sp2=" << sp2 << "\n";
    sp2 = nullptr;
    cout << "sp2=" << sp2 << "\n";
}

void ToStringExample() {
    std::random_device rd;
    std::default_random_engine generator { rd() };
    std::uniform_int_distribution<int8_t> distribution(1, 6);
    for (int i = 0; i < 5; ++i) {
        auto dice_roll = distribution(generator);
        cout << "roll #" << i << ": ";
        cout << std::to_string(dice_roll) << "\n";
    }
}

void OtherFeaturesExamples() {

    std::vector<std::map<string, uint64_t>> v { { { "key1", 17 }, { "key2", 23 } } };

    std::vector<std::map<string, uint64_t>>::const_iterator cit1 = v.cbegin();
    const std::map<string, uint64_t>& m1 = (*cit1);

    auto cit2 = v.cbegin();
    auto& m2 = (*cit2);

    // Error: m2.insert(std::make_pair("key3", 91 ));

    cout << "m1=" << *m1.begin() << "\n";
    cout << "m2=" << *m2.begin() << "\n";

    cout << "\n" << std::make_pair("p", 2) << "\n";

    std::array<int, 4> firstIntArray { { 1, 2, 3, 4 } };
    cout << ContainerToString(firstIntArray) << "\n";

    std::vector<std::shared_ptr<string>> right_angle_bracket;
    cout << ContainerToString(right_angle_bracket) << "\n";
}

using namespace std;

pair<string, string::size_type> CreateMapEntry(const string& s) {
    return {s, s.length()};
}

void InitializationSyntaxExample() {
    string str1 { "test" };
    int v1 { 4 };
    map<string, string::size_type> map1 { { str1, v1 }, { "key1", 3 }, { "a", 1 } };
    map1.insert(CreateMapEntry("modern"));
    cout << ContainerToString(map1, ",\n") << "\n";
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
        cout << "r1=" << r1 << "\n";
    }
    {
        std::complex<double> r2 { 1, 0 };
        for (const auto& c : cvector) {
            r2 *= c;
        }
        cout << "r2=" << r2 << "\n";
    }
}

int main() {

    INVOKE_METHOD(OtherFeaturesExamples());

    INVOKE_METHOD(SmartPointersExample());

    INVOKE_METHOD(ToStringExample());

    INVOKE_METHOD(ArraysExamples());

    INVOKE_METHOD(MyClass::MyClassExample());

    INVOKE_METHOD(ReturnValueOptimizationExample::Execute());

    INVOKE_METHOD(InitializationSyntaxExample());

    INVOKE_METHOD(RangeBasedLoopExample());

    return 0;

}

