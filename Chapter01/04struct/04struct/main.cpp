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
    ganjang_chicken.name = "����ġŲ";
    ganjang_chicken.price = 19000;
    ganjang_chicken.count = 0;

    std::cout   << "����: " << ganjang_chicken.idx << "\n" 
                << "��ǰ��: " << ganjang_chicken.name << "\n"
                << "����: " << ganjang_chicken.price << "\n"
                << "�Ǹŷ�: " << ganjang_chicken.count << "\n" << std::endl;
    

	return 0;
}