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