#ifndef EXAMPLESHEADER_HPP_
#define EXAMPLESHEADER_HPP_

#include <stdafx.h>


template<typename A, typename B>
std::ostream& operator<< (std::ostream& o, const std::pair<A,B>& p) {
	return o << "std::pair["<< p.first << ", " << p.second << "]";
}

template<typename T>
std::ostream& operator<< (std::ostream& o, const std::shared_ptr<T>& i) {
	if(i == nullptr) {
		return o << "std::shared_ptr[count=" << i.use_count() << ",  nullptr]";
	}
	return o << "std::shared_ptr[count=" << i.use_count() << ", addr="<< static_cast<void*>(&*i) << ", value=" << (*i) << "]";
}

#endif /* EXAMPLESHEADER_HPP_ */
