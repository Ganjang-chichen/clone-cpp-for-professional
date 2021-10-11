#pragma once
#include "stdafx.h"
#include "MyClass.h"


MyClass::MyClass() {

}

MyClass::~MyClass() {

}

int MyClass::get_var1() {
	return var1;
}

std::string MyClass::get_name() {
	return name;
}

std::vector<int> MyClass::get_list() {
	return list;
}

void MyClass::set_var1(int var) {
	var1 = var;
}

void MyClass::set_name(std::string name) {
	this->name = name;
}

void MyClass::set_list(std::vector<int> list) {
	this->list = list;
}