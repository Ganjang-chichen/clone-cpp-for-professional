#include <iostream>
#include<cmath>

int GetFibo(int n);

int main() {

	using namespace std;
	int n;
	cin >> n;

	// 그냥 for 문
	
	if (n == 0) {
		cout << 0 << "\n";
	}
	else if (n == 1 || n == 2) {
		cout << 1 << "\n";
	}
	else {
		int fibo1 = 0, fibo2 = 1, fibo3 = 1;
		for (int i = 0; i < n - 1; i++) {
			fibo3 = fibo1 + fibo2;
			fibo1 = fibo2;
			fibo2 = fibo3;
		}

		cout << fibo3 << "\n";
	}
	
	// 재귀함수
	//cout << GetFibo(n) << "\n";

	return 0;
}

int GetFibo(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return GetFibo(n - 1) + GetFibo(n - 2);
	}
}