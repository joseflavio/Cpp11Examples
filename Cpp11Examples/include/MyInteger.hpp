#ifndef MYINTEGER_HPP_
#define MYINTEGER_HPP_

#include <stdafx.h>

class MyInteger {

private:
	int _value;

public:
	MyInteger(int value) :
			_value(value) {
	}

	~MyInteger() {
		std::cout << "~MyInteger - _value=" << _value << std::endl;
	}

	int get() const {
		return _value;
	}

	static std::string to_string(const MyInteger& i) {
		return std::to_string(i._value);
	}

};

std::ostream& operator<< (std::ostream& o, const MyInteger& v) {
	return o << MyInteger::to_string(v);
}

#endif /* MYINTEGER_HPP_ */
