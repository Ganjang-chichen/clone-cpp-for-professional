#include<iostream>
#include<vector>

int main() {

	using namespace std;

	int N;
	cin >> N;

	vector<int> arr(2000001, 0);

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		arr[input + 1000000] = 1;
	}

	for (int i = 0; i < 2000001; i++) {
		if (arr[i]) {
			cout << i - 1000000 << "\n";
		}
	}

	return 0;
}