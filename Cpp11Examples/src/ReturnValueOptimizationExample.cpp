#include <ExamplesHeader.hpp>

#include <stdafx.h>

namespace ReturnValueOptimizationExampleTypes {

class RVO {
public:
    std::string _str;
    RVO(const std::string iStr): _str(iStr) {
    }
    RVO(const RVO& i): _str(i._str){
        std::cout << "A copy of RVO._str=" << _str << " was made.\n";
    }
    RVO(RVO&& i) : _str(std::move(i._str)) {
        std::cout << "The RVO._str=" << _str << " was moved.\n";
    }
};

RVO Working() {
    RVO first { "first" };
    return first;
}

RVO NotWorking(bool c = true) {
    RVO first { "first" };
    RVO second { "second" };
    return c ? first : second;
}

RVO Working2(bool c = true) {
    RVO first { "first" };
    RVO second { "second" };
    RVO third = c ? std::move(first) : std::move(second);
    std::cout << "f=" << first._str << ", ";
    std::cout << "s=" << second._str << std::endl;
    return third;
}

}// namespace

void ReturnValueOptimizationExample::Execute() {
    using namespace ReturnValueOptimizationExampleTypes;
    std::cout << "ReturnValueOptimizationExample" << std::endl << "===" << std::endl << std::endl;
    std::cout << "- RVO Working:" << std::endl;
    std::cout << Working()._str << std::endl;
    std::cout << "- RVO Not working:" << std::endl;
    std::cout << NotWorking()._str << std::endl;
    std::cout << "- RVO Working with move:" << std::endl;
    std::cout << Working2()._str << std::endl;
    std::cout << std::endl;
}

