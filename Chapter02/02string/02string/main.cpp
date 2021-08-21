#include<iostream>
#include<string>

int main() {
    using namespace std;

    string s1 = "ab";
    string s2 = "cd";
    string s3 = "ab";

    cout << s1 + s2 << endl;        // 출력 abcd
    cout << (s1 == s3) << endl;     // 출력 1
    cout << (s1 < s2) << endl;      // 출력 1
    cout << (s1 > s2) << endl;      // 출력 0
	
    s1[1] = 'B';
    cout << s1 << endl;             // 출력 aB

    const char* s4 = s1.c_str();    // string to char*
    cout << s4 << endl;

    string s5 = s4;                 // char* to string
    cout << s5 << endl;

    int integer = 333;
    string s6 = to_string(integer); // int to string
    cout << "integer : " + s6 << endl;

    int integer_c = stoi(s6);       // string to int
    cout << integer_c + 2 << endl;

    float f = 3.141592f;
    string s7 = to_string(f);       // float to string
    cout << "float : " + s7 + "f" << endl;

    float f_c = stof(s7);           // string to float
    cout << f_c + 2 << endl;

    // 나머지 변환은 생략

    string text = "hello \n \t fff\rg";
    cout << text << endl;

    // 다음의 방식을 로우 문자 리터럴이라 한다.
    string text2 = R"("고래야 적어도 바다는 네가 가졌으면 좋겠어" // 로우 문자열에선 주석도 안먹힌다.
"고래야 헤엄하던대로 계속 헤엄했으면 좋겠어"
    \r \n \t)";
    cout << text2 << endl;

    // 확장된 로우 문자열 리터럴. )을 사용할 수 있다.
    // 재일 앞, 끝부분을 구분자라 하는데 양 끝이 같아야 하고, 사용자가 정의한다.
    string text3 = R"d-char-sequence(여기선 괄호() 사용가능해유 )d-char-sequence";
    cout << text3 << endl;

    string text4 = R"wtf(쮸압쮸압)wtf";
    cout << text4 << endl;

	return 0;
}