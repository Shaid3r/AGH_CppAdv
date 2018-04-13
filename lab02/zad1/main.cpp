#include <iostream>
#include "UniquePointer.h"

class A {
public:
	A(const std::string& name) : name(name) 
		{ std::cout << "Created " << name << std::endl; }

	~A () { std::cout << "Destroyed " << name << std::endl; }

	void print(const std::string &s="") const 
		{ std::cout << name << " " << s << std::endl; }

private:
	const std::string name;
};

template<typename T>
UniquePointer<T>&& foo(UniquePointer<T> ptr) {
	std::cout << "Start foo" << std::endl;
	ptr.Get()->print();
	std::cout << "End foo" << std::endl;
	return std::move(ptr);
}

int main() {
	UniquePointer<A> ptr(new A("First"));
	ptr = foo(std::move(ptr));
	ptr.Get()->print("Raw pointer");
	(*ptr).print("Dereference");

	// Try of memory leak
	ptr = std::move(ptr);

	// Should not compile
#ifdef FAIL
	UniquePointer<A> copy = ptr;
	ptr = UniquePointer<A>(A("move"));
#endif // FAIL

	if (ptr) 
		std::cout << "Non empty ptr" << std::endl;
	else
		std::cout << "Empty ptr" << std::endl;
}