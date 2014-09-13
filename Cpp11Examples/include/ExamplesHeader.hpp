#ifndef EXAMPLESHEADER_HPP_
#define EXAMPLESHEADER_HPP_

#include <iostream>


template<typename A, typename B>
std::ostream& operator<< (std::ostream& o, const std::pair<A,B>& p) {
	return o << p.first << " - " << p.second;
}


#endif /* EXAMPLESHEADER_HPP_ */
