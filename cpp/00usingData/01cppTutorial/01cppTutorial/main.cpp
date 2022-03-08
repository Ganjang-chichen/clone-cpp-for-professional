#include<iostream>

// visual studio 주석 단축키 crtl + k -> ctrl + c
//				 주석 해재키 ctrl + k -> ctrl + u

// 0이 아닌 초기화 값이 있으면 .data 영역
// 초기값이 0이거나 초기값이 없으면 .bss 영역

char a; // 1바이트
short b; // 2바이트
int c; // 4바이트
__int64 d; // 8바이트

bool isTrue = true; // 1 바이트
bool isFakse = false; // 실질적으로 true == 1, false == 0

float attackSpeed = 0.6391f; // 4바이트
double attackSpeed2 = 0.142; // 8바이트

// UTF-8
// 영어, 숫자 1바이트
// 유럽 지역문자 2바이트
// 한글, 한자 3바이트

// UTF-16
// 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// 매우 예외적인 고대 문자 만 4 바이트(사실상 무시 가능)
wchar_t wch = L'안';

// 문자열
char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
char str2[] = "hello";
wchar_t str3[] = L"안녕";

// 상수 constant: 한번 정해지면 절대 안 바뀜
// 그냥 const 는 반드시 .rodata 이진 않다. 컴파일러 마음.
const int NORMAL = 0;
const int EPIC = 1;
const int UNIQUE = 2;
const int LEGEND = 3;

// 전역변수

// [데이터 영역]
// .data (초기값 있는 경우)
int alpha = 2232;

// .bss (초기값 없는 경우)
int beta;

// .rodata (읽기 전용 데이터)
const char* msg = "Hello world";

// 유의사항

int main() {

	using namespace std;

	cout << attackSpeed << "\n";

	// 유니코드 사용 시
	wcout.imbue(locale("kor"));
	wcout << wch << "\n";

	return 0;
}