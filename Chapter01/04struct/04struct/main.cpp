#pragma once
#include <iostream>
#include <string>

struct Chicken {
    int idx;
    std::string name;
    int price;
    int count;
};

int main() {
	
    Chicken ganjang_chicken;

    ganjang_chicken.idx = 0;
    ganjang_chicken.name = "간장치킨";
    ganjang_chicken.price = 19000;
    ganjang_chicken.count = 0;

    std::cout   << "목차: " << ganjang_chicken.idx << "\n" 
                << "상품명: " << ganjang_chicken.name << "\n"
                << "가격: " << ganjang_chicken.price << "\n"
                << "판매량: " << ganjang_chicken.count << "\n" << std::endl;
    

	return 0;
}