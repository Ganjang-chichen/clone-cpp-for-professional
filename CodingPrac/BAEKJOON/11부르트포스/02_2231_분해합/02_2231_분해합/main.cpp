#include<iostream>
#include<cmath>
#include<vector>

std::vector<int> calc_digit(int N);

int main() {

	using namespace std;

	int N;
	cin >> N;

	bool isExist = false;
	for (int i = 0; i < N; i++) {
		int sum = i;
		vector<int> temp = calc_digit(i);
		for (int j = 0; j < temp.size(); j++) {
			sum += temp[j];
		}
		if (N == sum) {
			cout << i << "\n";
			isExist = true;
			break;
		}
	}
	if (!isExist) {
		cout << 0 << "\n";
	}

	return 0;
}

std::vector<int> calc_digit(int N) {
	
	int digit = 0;
	while (true) {

		if (pow(10, digit) > N) {
			break;
		}

		digit++;
	}

	std::vector<int> value;
	int temp = N;
	for (int i = 0; i < digit; i++) {
		value.push_back((N / (int)pow(10, i)) % 10);
	}

	return value;
}