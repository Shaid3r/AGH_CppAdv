#include <string>
#include <iostream>
#include <exception>
#include <optional>
#include <string_view>


struct person {
	std::string first_name;
	std::optional<std::string> middle_name;
	std::string last_name;

	bool is_middle_name_known() const {
		return middle_name.has_value();
	}

	std::string get_middle_name() const {
		return middle_name.value_or("");
	}

};

int main() {
    person mateo = person();
	std::cout << mateo.is_middle_name_known() << std::endl;
    std::cout << mateo.get_middle_name() << std::endl;
    mateo.middle_name= "Tomasz";
	std::cout << mateo.is_middle_name_known() << std::endl;
    std::cout << mateo.get_middle_name() << std::endl;
}

