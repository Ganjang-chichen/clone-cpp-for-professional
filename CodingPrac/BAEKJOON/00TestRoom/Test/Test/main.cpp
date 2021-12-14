#include<iostream>

int fibo(int n);
int main() {

	using namespace std;

	int n;
	cin >> n;

	int value = fibo(n);
	cout << value << "\n";
	/*
	if (n == 0) {
		cout << 0 << "\n";
	}
	else if(n == 1) {
		cout << 1 << "\n";
	}
	else {
		int fibo0 = 0, fibo1 = 1, fibo2;
		for (int i = 0; i < n - 1; i++) {
			fibo2 = fibo0 + fibo1;
			fibo0 = fibo1;
			fibo1 = fibo2;
		}

		cout << fibo2 << "\n";
	}
	*/

	return 0;
}

int fibo(int n) {

	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibo(n - 1) + fibo(n - 2);
	}
	
}