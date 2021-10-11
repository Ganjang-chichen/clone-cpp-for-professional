
#pragma once
#include "stdafx.h"
#include <memory>
#include "MyClass.h"

int main() {
	
	using namespace std;

	auto first = make_unique<MyClass>();

	first->set_var1(0);
	first->set_name("qwerty");
	vector<int> li = { 1,2,3,4,5 };
	first->set_list(li);

	cout << first->get_name() << "\n";
	cout << first->get_var1() << "\n";
	for (int i = 0; i < first->get_list().size(); i++) {
		cout << first->get_list()[i] << " ";
	}
	cout << "\n";


	MyClass second;
	second.set_var1(1);
	second.set_name("ytrewq");
	vector<int> li2 = { 5,4,3,2,1 };
	second.set_list(li2);

	cout << second.get_var1() << "\n";
	cout << second.get_name() << "\n";

	for (int i = 0; i < second.get_list().size(); i++) {
		cout << second.get_list()[i] << " ";
	}
	cout << "\n";

	return 0;

}