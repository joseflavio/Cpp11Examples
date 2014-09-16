#ifndef EXAMPLESHEADER_HPP_
#define EXAMPLESHEADER_HPP_

#include <stdafx.h>

namespace NullPtrExample {
template<typename T>
static void ThrowIfNull(T p) {
    if (p == nullptr) {
        throw std::exception();
    }
}
} // namespace NullPtrExample

namespace StronglyTypedEnumsExample {

enum class ExchangePolicy {
    NoExchange, ExchangePerBookedTrip
};

} // namespace

class ReturnValueOptimizationExample {
public:
    static void Execute();
};

#endif /* EXAMPLESHEADER_HPP_ */
