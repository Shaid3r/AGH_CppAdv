#include <iostream>
#include "List.h"

int main() {
	// Create a list containing integers
    List<int> l = { 7, 5, 16, 8 };
	// List<int> l;
	
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);

	List<int>::iterator it;
 
	std::cout << "[";
	for (List<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << " " << *it;
    std::cout << "]" << std::endl;
 
    // Iterate and print values of the list
    for (auto n : l) {
        std::cout << n << '\n';
    }
}