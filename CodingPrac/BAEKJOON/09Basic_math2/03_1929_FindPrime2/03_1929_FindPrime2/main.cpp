#include<iostream>
#include<memory.h>

void findPrime(int* arr, int n) { // n 이하 자연수에서 소수 찾기

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
	

	int M, N;
	cin >> M >> N;

	int* primeList = new int[N + 1];

	findPrime(primeList, N);
	for (int i = M; i <= N; i++) {
		if (primeList[i] == 0) {
			cout << i << " ";
		}
	}

	return 0;
}