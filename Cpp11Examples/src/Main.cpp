#include <stdafx.h>
#include <ExamplesHeader.hpp>
#include <MyInteger.hpp>

int main() {

	std::cout << std::endl << std::make_pair("p", 2) << std::endl;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,6);

	for (int i=0; i<100; ++i) {
		auto dice_roll = distribution(generator);
		// std::cout << std::to_string(dice_roll) << std::endl;
	}

	std::shared_ptr<int64_t> a { new int64_t { 8 } };
	std::cout << "a=" << a << std::endl;

	std::shared_ptr<MyInteger> b { new MyInteger(6) };

	//*a = 5;

	b = nullptr;

	// a.reset( new int64_t { 6 } );

	std::cout << "b=" << b << std::endl;

}
