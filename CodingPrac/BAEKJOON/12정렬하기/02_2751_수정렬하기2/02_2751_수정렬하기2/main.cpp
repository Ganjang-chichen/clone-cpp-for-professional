#include<iostream>
#include<vector>

int main() {

	using namespace std;

	int N;
	cin >> N;

	/* 그냥 야매
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
	*/

	int input;
	cin >> input;

	vector<int> list = {input};
	for (int i = 0; i < N - 1; i++) {
		cin >> input;
		
		if (input <= list[0]) {
			list.insert(list.begin(), input);
		}
		else if (input >= list[list.size() - 1]) {
			list.push_back(input);
		}
		else {

			int range = list.size() - 1;
			int point = 0;
			while (true)
			{
				if (range > 1) {
					range /= 2;
				}

				if (list[point] <= input && input <= list[point + 1]) {
					list.insert(list.begin() + point + 1, input);
					break;
				}
				else if (list[point] > input) {
					point -= range;
				}
				else if (list[point + 1] < input) {
					point += range;
				}

			}

		}
	}

	for (int i = 0; i < N; i++) {
		cout << list[i] << "\n";
	}

	return 0;
}