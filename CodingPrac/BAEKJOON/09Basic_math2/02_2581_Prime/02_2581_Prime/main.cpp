#include<iostream>
#include<vector>

std::vector<int> findPrime(int n) { // n ���� �ڿ������� �Ҽ� ã��

	std::vector<int> value;

	if (n < 2) { // n < 2 ������ �� ����
		return value;
	}

	value.push_back(2);

	if (n == 2) { // n == 2 �϶� 2 �ϳ�
		return value;
	}

	for (int i = 3; i <= n; i = i + 2) { // ������ ¦���� �Ҽ��ȵ�
		bool isNotPrime = false;

		for (int j = 0; j < value.size(); j++) { // �Ҽ� ����
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

	int M, N;
	cin >> M >> N;

	vector<int> primeList = findPrime(10000);

	int sum = 0;
	int min = 0;
	for (int i = 0; i <= primeList.size(); i++) {
		if (primeList[i] > N) {
			break;
		}

		if (primeList[i] >= M) {
			if (sum == 0) {
				min = primeList[i];
			}
			
			sum += primeList[i];
		}

	}

	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << "\n" << min;
	}

	return 0;
}