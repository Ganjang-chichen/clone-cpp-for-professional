#include<iostream>
#include<vector>

std::vector<int> findPrime(int n) { // n 이하 자연수에서 소수 찾기

	std::vector<int> value;

	if (n < 2) { // n < 2 이하일 때 없음
		return value;
	}

	value.push_back(2);

	if (n == 2) { // n == 2 일때 2 하나
		return value;
	}

	for (int i = 3; i <= n; i = i + 2) { // 어차피 짝수는 소수안됨
		bool isNotPrime = false;
		for (int j = 0; j < value.size(); j++) { // 소수 검출
			if (i % value[j] == 0) {
				isNotPrime = true;
				break;
			}
		}

		if (isNotPrime) {
			continue;
		}
		else {
			value.push_back(i);
		}
	}

	return value;
}

int main() {

	using namespace std;

	vector<int> prime = findPrime(1000);

	int N;
	cin >> N;
	
	int count = 0;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		for (int j = 0; j < prime.size(); j++) {
			if (input == prime[j]) {
				count++;
				break;
			}
			else if (input < prime[j]) {
				break;
			}
		}
	}

	cout << count;

	return 0;

}