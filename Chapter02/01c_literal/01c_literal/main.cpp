#include<iostream>

int main() {
    using namespace std;

    //char* ptr = "hello";    // 문자열 리터럴을 변수에 대입
    //ptr[1] = 'a';           // 정의되지 않은 동작. 무슨일이 일어날 지 알 수 없다.
                              // visual studio 에서는 자체 걸러준다.
                              
    // 위의 경우 때문에 문자열 리터럴을 변수로 사용 시 const를 사용하는것이 안전하다.
    // 왜냐하면 컴파일러에서 걸러주기 때문이다.
    const char* ptr2 = "hello";  // 문자열 리터럴을 변수에 대입
    //ptr2[1] = 'a';              // 컴파일 에러! 읽기 전용 메모리에 쓰기시도!
    cout << ptr2 << endl;

        // 문자열 리터럴은 문자 배열의 초깃값으로 사용가능하다.
    char arr[] = "hello";   // 컴파일러가 자동으로 문자열 배열크기에 맞게 복제 및 메모리 할당
    arr[1] = 'a';           // 이 경우는 배열 내용을 수정가능하다. 
                            // 왜냐하면 이 경우는 리터럴 풀링에 포함되지 않기 때문이다.
    cout << arr << endl;
	return 0;
}