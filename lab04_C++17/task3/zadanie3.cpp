/*
Prosze uzupelnic miejsca oznaczone "..." kodem tak,
aby program sie kompilowal oraz zwracal dla podanej
w mainie wartosci odpowiedni wynik:
double - odcinanie wartosci po przecinku
int - potega 3 stopnia
string - odwrotnosc lancucha

*/

#include <string>
#include <iostream>
#include <string_view>
#include <variant>
#include <algorithm>

struct Stuff {
	std::variant<int, double, std::string> data;
};

void handleData(int i) { std::cout << i * i * i << std::endl; }
void handleData(double d){ std::cout << static_cast<int>(d) << std::endl; }
void handleData(std::string_view s){ 
	std::string reversed(s);
	std::reverse_copy(s.begin(), s.end(), reversed.begin());
	std::cout << reversed << std::endl;
}

struct ThatLambda {
	void operator()(auto &&d) {
		handleData(d);
	}
};

int main() {
    Stuff stuff = Stuff();
    ThatLambda thatLambda;
    stuff.data = "znak";
	std::visit(thatLambda, stuff.data);
	stuff.data = 4;
	std::visit(thatLambda, stuff.data);
	stuff.data = 4.2;
	std::visit(thatLambda, stuff.data);
}