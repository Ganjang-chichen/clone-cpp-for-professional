#include<vector>
#include<iterator>

#include<string>
#include<iostream>

int main() {

    std::vector<std::string> myVector = { "first", "second" }; // �迭ó�� ����
    myVector.push_back("third"); // ���� �迭�� �߰�
    myVector.push_back("forth");

    for (const auto& str : myVector) {
        std::cout << str << std::endl;
    }

    // �ݺ��� Ȱ��
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