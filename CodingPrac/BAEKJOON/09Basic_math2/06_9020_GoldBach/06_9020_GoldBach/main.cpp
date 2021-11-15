#include <iostream>
#include<memory.h>

// 에라토스테네스의 채
void findPrime(int* arr, int n) { // n 이하 자연수에서 소수 찾기 0이면 소수

	if (n < 2) {
		return;
	}
	memset(arr, 0, (n + 1) * sizeof(int));
	int point = 2;

	arr[0] = 1;
	arr[1] = 1;

	while (point <= n) {

		if (arr[point] == 1) {
			point++;
			continue;
		}

		for (int i = 2;; i++) {
			if (point * i > n) {
				break;
			}
			else {
				arr[point * i] = 1;
			}
		}

		point++;
	}

	return;
}
int main() {

	using namespace std;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int input;
		cin >> input;

		int* primeList = new int[input + 1];
		findPrime(primeList, input);

		int half = input / 2;
		int prime_less, prime_high;

		if (half % 2 == 1) {
			prime_less = half;
			prime_high = half;
		}
		else {
			prime_less = half - 1;
			prime_high = half + 1;
		}

		while (true) {

			if (!primeList[prime_less] && !primeList[prime_high]) {
				cout << prime_less << " " << prime_high << "\n";
				break;
			}

			prime_less -= 2;
			prime_high += 2;

			if (prime_less < 2) {
				cout << "error" << "\n";
				break;
			}

		}

	}


	return 0;
}