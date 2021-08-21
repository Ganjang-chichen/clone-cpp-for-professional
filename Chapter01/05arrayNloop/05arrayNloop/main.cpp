#include <iostream>
#include <string>
#include <array>

int main() {

	std::array<std::string, 4> str_li = { "show", "me", "the", "money"};

	for (int i = 0; i < str_li.size(); i++) {
		std::cout << "0 : " << str_li[i] << std::endl;
	}

	for (std::string str : str_li) {
		std::cout << "1 : " << str << std::endl;
	}

	int j = 0;
	while (j < 3){
		std::cout << "2 : " << str_li[j] << std::endl;
		j++;
	}

	do{
		std::cout << "3 : " << str_li[j] << std::endl;
		j++;
	} while (j < 3);

	return 0;
}