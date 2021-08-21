#include<vector>
#include<iterator>

#include<string>
#include<iostream>

int main() {

    std::vector<std::string> myVector = { "first", "second" }; // 배열처럼 선언
    myVector.push_back("third"); // 기존 배열에 추가
    myVector.push_back("forth");

    for (const auto& str : myVector) {
        std::cout << str << std::endl;
    }

    // 반복자 활용
    for (auto iterator = std::cbegin(myVector);
        iterator != std::cend(myVector); ++iterator) {
        std::cout << *iterator << std::endl;
    }

    for (auto iterator = std::cbegin(myVector);
        iterator != std::cend(myVector); iterator++) {
        std::cout << *iterator << std::endl;
    }

    return 0;
}