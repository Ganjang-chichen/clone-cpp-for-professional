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
	아래의 경우 위에서 추론된 타입과 다름으로 오류가 발생한다.
	즉 반환값을 auto로 설정하더라도 리턴타입은 하나로 통일된다.
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