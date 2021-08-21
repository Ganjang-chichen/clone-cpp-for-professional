#include<iostream>
#include<string>

int main() {
    using namespace std;

    string s1 = "ab";
    string s2 = "cd";
    string s3 = "ab";

    cout << s1 + s2 << endl;        // ��� abcd
    cout << (s1 == s3) << endl;     // ��� 1
    cout << (s1 < s2) << endl;      // ��� 1
    cout << (s1 > s2) << endl;      // ��� 0
	
    s1[1] = 'B';
    cout << s1 << endl;             // ��� aB

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

    // ������ ��ȯ�� ����

    string text = "hello \n \t fff\rg";
    cout << text << endl;

    // ������ ����� �ο� ���� ���ͷ��̶� �Ѵ�.
    string text2 = R"("���� ��� �ٴٴ� �װ� �������� ���ھ�" // �ο� ���ڿ����� �ּ��� �ȸ�����.
"���� ����ϴ���� ��� ��������� ���ھ�"
    \r \n \t)";
    cout << text2 << endl;

    // Ȯ��� �ο� ���ڿ� ���ͷ�. )�� ����� �� �ִ�.
    // ���� ��, ���κ��� �����ڶ� �ϴµ� �� ���� ���ƾ� �ϰ�, ����ڰ� �����Ѵ�.
    string text3 = R"d-char-sequence(���⼱ ��ȣ() ��밡������ )d-char-sequence";
    cout << text3 << endl;

    string text4 = R"wtf(������)wtf";
    cout << text4 << endl;

	return 0;
}