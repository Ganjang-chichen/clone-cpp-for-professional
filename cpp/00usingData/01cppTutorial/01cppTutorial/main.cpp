#include<iostream>

// visual studio �ּ� ����Ű crtl + k -> ctrl + c
//				 �ּ� ����Ű ctrl + k -> ctrl + u

// 0�� �ƴ� �ʱ�ȭ ���� ������ .data ����
// �ʱⰪ�� 0�̰ų� �ʱⰪ�� ������ .bss ����

char a; // 1����Ʈ
short b; // 2����Ʈ
int c; // 4����Ʈ
__int64 d; // 8����Ʈ

bool isTrue = true; // 1 ����Ʈ
bool isFakse = false; // ���������� true == 1, false == 0

float attackSpeed = 0.6391f; // 4����Ʈ
double attackSpeed2 = 0.142; // 8����Ʈ

// UTF-8
// ����, ���� 1����Ʈ
// ���� �������� 2����Ʈ
// �ѱ�, ���� 3����Ʈ

// UTF-16
// ���ĺ�, ����, �ѱ�, ���� �� ���� ��κ� ���� 2����Ʈ
// �ſ� �������� ��� ���� �� 4 ����Ʈ(��ǻ� ���� ����)
wchar_t wch = L'��';

// ���ڿ�
char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
char str2[] = "hello";
wchar_t str3[] = L"�ȳ�";

// ��� constant: �ѹ� �������� ���� �� �ٲ�
// �׳� const �� �ݵ�� .rodata ���� �ʴ�. �����Ϸ� ����.
const int NORMAL = 0;
const int EPIC = 1;
const int UNIQUE = 2;
const int LEGEND = 3;

// ��������

// [������ ����]
// .data (�ʱⰪ �ִ� ���)
int alpha = 2232;

// .bss (�ʱⰪ ���� ���)
int beta;

// .rodata (�б� ���� ������)
const char* msg = "Hello world";

// ���ǻ���

int main() {

	using namespace std;

	cout << attackSpeed << "\n";

	// �����ڵ� ��� ��
	wcout.imbue(locale("kor"));
	wcout << wch << "\n";

	return 0;
}