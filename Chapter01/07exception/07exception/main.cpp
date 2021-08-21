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
    i++;    // 파라미터 변수의 복제본이기 때문에 원래 변수에는 지장 없다.
}

void addOne_mk2(int& i) {
    i++;    // 원본 파라미터의 변수값이 1 증가한다.
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
    std::cout << "원래 값 : " << integer << std::endl;
    addOne(integer);
    std::cout << "참조 x  : " << integer << std::endl;
    addOne_mk2(integer);
    std::cout << "참조 o  : " << integer << std::endl;
    return 0;
}