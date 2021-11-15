#include<iostream>
#include<memory.h>

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

	int N;
	
	while (true){
		cin >> N;
		int* prime = new int[2 * N + 1];

		if (N < 1) {
			break;
		}

		findPrime(prime, 2 * N);

		int count = 0;
		for (int i = N + 1; i <= 2 * N; i++) {
			if (prime[i] == 0) {
				count++;
			}
		}

		cout << count << "\n";
		
		delete prime;
	}
	
	return 0;
}

