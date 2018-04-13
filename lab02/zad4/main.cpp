#include <iostream>
#include <type_traits>
#include <stdexcept>

template<typename T, bool>
struct Multi_impl {
	T operator()(const T &x, const T &) {
		throw std::invalid_argument("cannot multiply non arithmetic types");
		return x;
	}
};

template<typename T>
struct Multi_impl <T, true> {
	T operator()(const T &x, const T &y) {
		return x * y;
	}
};

template<typename T>
auto multiply(const T &x, const T &y) {
	Multi_impl<T, std::is_arithmetic<T>::value> multi;
	return multi(x, y);
}

int main() {
	std::cout << multiply(2, 3) << std::endl;

	std::cout << multiply(std::string("dsa"), std::string("dfsa")) << std::endl;
}