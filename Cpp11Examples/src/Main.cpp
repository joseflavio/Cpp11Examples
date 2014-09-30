#include <stdafx.h>

#include <PrintUtils.hpp>
#include <ExamplesHeader.hpp>

#include <MyInteger.hpp>

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

void arraysExamples() {
    {
        std::array<std::string, 3> a { { "foo", "baz", "bar" } };
        std::sort(a.begin(), a.end());
        for (const auto& v : a) {
            std::cout << v << ' ';
        }
    }
    {
        std::array<int, 5> a { { 1, 2, 3, 4, 5 } };
        std::reverse(a.begin(), a.end());
        for (const auto& v : a) {
            std::cout << v << ' ';
        }
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
    // auto start =  std::chrono:: high_resolution_clock::now();

}

int main() {
    arraysExamples();

    std::cout << std::endl << std::make_pair("p", 2) << std::endl;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 6);

    for (int i = 0; i < 3; ++i) {
        auto dice_roll = distribution(generator);
        std::cout << std::to_string(dice_roll) << std::endl;
    }

    std::shared_ptr<int64_t> a { new int64_t { 8 } };
    std::cout << "a=" << a << std::endl;

    std::shared_ptr<MyInteger> b { new MyInteger(6) };

    NullPtrExample::ThrowIfNull(b);

    std::array<int, 4> firstIntArray { { 1, 2, 3, 4 } };
    std::cout << ContainerToString(firstIntArray) << std::endl;

    //*a = 5;

    b = nullptr;

    // a.reset( new int64_t { 6 } );

    std::cout << "b=" << b << std::endl;

    ReturnValueOptimizationExample::Execute();

    std::vector<std::shared_ptr<std::string>> right_angle_bracket;
    std::cout << ContainerToString(right_angle_bracket) << std::endl;

}
