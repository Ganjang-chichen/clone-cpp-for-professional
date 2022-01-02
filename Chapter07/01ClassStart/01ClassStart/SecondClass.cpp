#include "SecondClass.h"

SecondClass::SecondClass(){}
SecondClass::~SecondClass() {}

int SecondClass::getSecond() {
	return this->secondInteger;
}

void SecondClass::setSecond(int num) {
	this->secondInteger = num;
}