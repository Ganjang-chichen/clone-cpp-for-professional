#include <iostream>
#include <string>

void foo(int i);

void foo2(std::string s) {
	std::cout << s << std::endl;
}

std::string foo3(char* c) {
	std::string str(c);
	return str;
}

auto foo4(int i) {

	switch (i)
	{
	case 0 :
		return 44.4;
/*
	�Ʒ��� ��� ������ �߷е� Ÿ�԰� �ٸ����� ������ �߻��Ѵ�.
	�� ��ȯ���� auto�� �����ϴ��� ����Ÿ���� �ϳ��� ���ϵȴ�.
	case 1 :
		return "q";
*/
	default:
		break;
	}

}

int main() {
	foo(10);
	foo2("chicken!");
	char c[] = "ganjang";
	std::cout << foo3(c) << std::endl;
	foo4(0);
}

void foo(int i) {
	std::cout << i << std::endl;
}