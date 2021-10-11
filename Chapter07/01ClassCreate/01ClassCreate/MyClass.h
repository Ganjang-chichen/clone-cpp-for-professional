#pragma once
#include "stdafx.h"

class MyClass {
private:
	int var1;
	std::string name;
	std::vector<int> list;
public:
	MyClass();
	~MyClass();
	
	// getter
	int get_var1();
	std::string get_name();
	std::vector<int> get_list();

	// setter
	void set_var1(int var);
	void set_name(std::string name);
	void set_list(std::vector<int> list);


};