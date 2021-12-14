#include<iostream>

int main() {

	using namespace std;

	int N;
	cin >> N;

	int pactorial = 1;
	for (int i = 1; i <= N; i++) {
		pactorial *= i;
	}

	cout << pactorial;

	return 0;
}

