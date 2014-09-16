#ifndef PRINTUTIL_HPP_
#define PRINTUTIL_HPP_

#include <stdafx.h>

template<typename T>
std::string ContainerToString(const T& p) {
	std::stringstream ss;
	for (const auto& current:p) {
		ss << current;
	}
	return ss.str();
}

template<typename A, typename B>
std::ostream& operator<<(std::ostream& o, const std::pair<A, B>& p) {
    return o << "std::pair[" << p.first << ", " << p.second << "]";
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
