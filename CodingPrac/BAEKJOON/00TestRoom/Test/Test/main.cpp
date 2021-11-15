#include<iostream>
#include<memory.h>

void findPrime(int * primeList, int n) { // 0이면 소수, 1이면 소수가 아님

	if (n < 2) {
		return;
	}
	memset(primeList, 0, sizeof(int) * (n + 1));
	primeList[0] = 1;
	primeList[1] = 1;

	int point = 2;
	
	while (point <= n) {

		if (primeList[point] == 1) {
			point++;
			continue;
		}

		for (int i = 2;; i++) {
			if (point * i > n) {
				break;
			}

			primeList[point * i] = 1;
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

		if (input == 4) {
			cout << "2 2\n";
			continue;
		}

		int* primeList = new int[input + 1];
		findPrime(primeList, input);

		int half = input / 2; // 20 -> 10 -> 11 + 9 -> 13 + 7

		int prime_less, prime_high;

		if (half % 2 == 0) {
			prime_less = half - 1;
			prime_high = half + 1;
		}
		else { // 30 -> 15 -> 13 + 17
			prime_less = half;
			prime_high = half;
		}

		while (true){

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