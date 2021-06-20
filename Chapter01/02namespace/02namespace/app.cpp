/*
 코드 내에 IO 스트림이 없어도 사용할 수 있는이유는
 my_namespace.h 파일에서 include를 이미 했기 때문이다.
 두 파일 다 iostream을 include 하게 된다면 
 progma once 등의 전처리 없이는 오류가 발생한다.
*/
#include "my_namespace.h" // 헤더파일로 만든 네임 스페이스

namespace mycode_mk2 { // 코드 내에서도 만들 수 있다!
	int some_integer = 0;
	void foo() {
		std::cout << "이 foo() 함수는 코드 내에서 만들었어요!" << std::endl;
	}
}

int main() {

	std::cout << "헤더파일에서 foo() 함수 호출!" << std::endl;
	mycode::foo();

	std::cout << "코드내에서 foo() 함수 호출!" << std::endl;
	mycode_mk2::foo();

	using mycode_mk2::some_integer;
	std::cout << "이 경우 some_integer 만 스코프 생략!" << std::endl;
	std::cout << some_integer << std::endl;
	// foo(); << 에러 발생

	using namespace mycode; // 스코프 없이 foo() 호출 가능
	foo();

	using namespace mycode_mk2;
	//foo(); 이 경우 다시 같은 이름의 foo()함수가 2개 생겨서 스코프 지정을 해야한다.


	return 0;
}