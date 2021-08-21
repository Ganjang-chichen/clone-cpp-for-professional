#include<stdexcept>

double divideNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be 0");
    }
    return numerator / denominator;
}

#include<iostream>
#include<exception>

void addOne(int i) {
    i++;    // �Ķ���� ������ �������̱� ������ ���� �������� ���� ����.
}

void addOne_mk2(int& i) {
    i++;    // ���� �Ķ������ �������� 1 �����Ѵ�.
}

int main() {
    try {
        std::cout << divideNumbers(2.5, 0.5) << std::endl;
        std::cout << divideNumbers(2.5, 0) << std::endl;
        std::cout << divideNumbers(2.5, 0.1) << std::endl;
    }
    catch (const std::exception& exception) {
        std::cout << "Exception caught : " << exception.what() << std::endl;
    }

    int integer = 0;
    std::cout << "���� �� : " << integer << std::endl;
    addOne(integer);
    std::cout << "���� x  : " << integer << std::endl;
    addOne_mk2(integer);
    std::cout << "���� o  : " << integer << std::endl;
    return 0;
}