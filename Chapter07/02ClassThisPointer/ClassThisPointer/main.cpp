#include<iostream>

static int someInteger = 666;

class MyClass
{
public:
	MyClass();
	~MyClass();

	void printInteger_mk1();
	void printInteger_mk2();
	void printInteger_mk3(int someInteger);

private:
	int someInteger = 3;
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

void MyClass::printInteger_mk1() {
	std::cout << "case 1: " << someInteger << " 전역변수와 우선순위\n";
	return;
}

void MyClass::printInteger_mk2() {
	std::cout << "case 2: " << this->someInteger << " this pointer 사용한 경우\n";
	return;
}

void MyClass::printInteger_mk3(int someInteger) {
	std::cout << "case 3: " << someInteger << " 입력변수 우선순위\n";
	std::cout << "case 4: " << this->someInteger << " this pointer 사용한 경우\n";
	return;
}

int main() {

	MyClass myClass;
	myClass.printInteger_mk1();
	myClass.printInteger_mk2();
	myClass.printInteger_mk3(444);


	return 0;
}