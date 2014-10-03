#ifndef PRINTUTIL_HPP_
#define PRINTUTIL_HPP_

#include <stdafx.h>

#define INVOKE_METHOD(VAR) {\
    std::cout << "EXECUTING " << #VAR << std::endl;\
    Timer t0;\
    VAR;\
    Timer t1;\
    std::cout<<std::endl<<"FINISHED EXECUTING - elapsed = "<<Timer::Elapsed(t0,t1)<<std::endl<<std::endl; }

template<typename A, typename B>
std::ostream& operator<<(std::ostream& o, const std::pair<A, B>& p) {
    return o << "std::pair[" << p.first << ", " << p.second << "]";
}

template<typename T>
std::string ContainerToString(const T& p, const std::string separator = ", ") {
    std::stringstream ss;
    bool first = true;

    for (const auto & current : p) {
        if (first) {
            first = false;
        } else {
            ss << separator;
        }
        ss << current;
    }

    return ss.str();
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const std::shared_ptr<T>& i) {
    if (i == nullptr) {
        return o << "std::shared_ptr[count=" << i.use_count() << ", nullptr]";
    }
    return o << "std::shared_ptr[count=" << i.use_count() << ", addr="
            << static_cast<void*>(&*i) << ", value=" << (*i) << "]";
}

#endif /* PRINTUTIL_HPP_ */
