#include <string>
#include <iostream>

int main() {
	const std::string myString = "Hello World";

	if (auto it = myString.find("Hello"); it != std::string::npos)
		std::cout << it << " Hello\n";

	if (auto it2 = myString.find("World"); it2 != std::string::npos)
		std::cout << it2 << " World\n";
}
