/*
 �ڵ� ���� IO ��Ʈ���� ��� ����� �� �ִ�������
 my_namespace.h ���Ͽ��� include�� �̹� �߱� �����̴�.
 �� ���� �� iostream�� include �ϰ� �ȴٸ� 
 progma once ���� ��ó�� ���̴� ������ �߻��Ѵ�.
*/
#include "my_namespace.h" // ������Ϸ� ���� ���� �����̽�

namespace mycode_mk2 { // �ڵ� �������� ���� �� �ִ�!
	int some_integer = 0;
	void foo() {
		std::cout << "�� foo() �Լ��� �ڵ� ������ ��������!" << std::endl;
	}
}

int main() {

	std::cout << "������Ͽ��� foo() �Լ� ȣ��!" << std::endl;
	mycode::foo();

	std::cout << "�ڵ峻���� foo() �Լ� ȣ��!" << std::endl;
	mycode_mk2::foo();

	using mycode_mk2::some_integer;
	std::cout << "�� ��� some_integer �� ������ ����!" << std::endl;
	std::cout << some_integer << std::endl;
	// foo(); << ���� �߻�

	using namespace mycode; // ������ ���� foo() ȣ�� ����
	foo();

	using namespace mycode_mk2;
	//foo(); �� ��� �ٽ� ���� �̸��� foo()�Լ��� 2�� ���ܼ� ������ ������ �ؾ��Ѵ�.


	return 0;
}