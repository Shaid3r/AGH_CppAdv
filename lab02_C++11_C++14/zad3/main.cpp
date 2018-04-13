#include <iostream>
#include "Array.h"

int main() {
	// Create an array containing integers
    Array<int> a = { 7, 5, 16, 8 };

	a.print();
	a.append({1,2,3});
	a.print();

	Array<int> b(5);
	b.print();
}