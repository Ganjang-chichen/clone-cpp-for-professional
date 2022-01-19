#include<iostream>
#include<string>
#include<memory.h>

int main() {

	using namespace std;

	string N;
	cin >> N;

	int countSort[10];
	memset(countSort, 0, sizeof(int) * 10);

	for (int i = 0; i < N.size(); i++) {
		int temp = N[i] - 48;
		countSort[temp]++;
	}

	string result = "";

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < countSort[i]; j++) {
			result += i + 48;
		}
	}

	cout << result << "\n";

	return 0;
}