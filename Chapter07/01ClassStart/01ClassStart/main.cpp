#include<iostream>

class FirstClass {
private:
	int firstNumber = 0;
	int secondNumber = 1;
public:
	FirstClass();
	FirstClass(int f, int s);
	~FirstClass();

	void setFNum(int num);
	int getFNum();

	void setSNum(int num) {
		firstNumber = num;
	}
	int getSNum() {
		return secondNumber;
	}
};

FirstClass::FirstClass() {}
FirstClass::FirstClass(int f, int s) {
	firstNumber = f;
	secondNumber = s;
}
FirstClass::~FirstClass(){
	std::cout << "first class erase\n";
}

void FirstClass::setFNum(int f) {
	firstNumber = f;
	return;
}

int FirstClass::getFNum() {
	return firstNumber;
}

int main() {

	FirstClass test0;
	test0.setFNum(1);
	test0.setSNum(1);
	std::cout << "test0 >> first number: " << test0.getFNum() << "  second number: " << test0.getSNum() << "\n";
	

	FirstClass test1(4, 44);
	std::cout << "test1 >> first number: " << test1.getFNum() << "  second number: " << test1.getSNum() << "\n";





	return 0;
}