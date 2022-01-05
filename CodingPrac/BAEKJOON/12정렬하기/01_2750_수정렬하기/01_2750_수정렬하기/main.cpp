#include<iostream>
#include<vector>

int main() {

	using namespace std;
	
	int N;
	cin >> N;

	vector<int> list;
	for (int i = 0; i < N; i++) {

		int input;
		cin >> input;
		
		bool isMax = false;
		for (int j = 1; j < list.size(); j++) {
			if (list[j - 1] <= input && list[j] > input) {
				isMax = true;
				list.insert(list.begin() + j, input);
				break;
			}
		}
		
		if (!isMax) {
			if (list.size()) {
				if (list[0] > input) {
					list.insert(list.begin(), input);
				}
				else {
					list.push_back(input);
				}
			}
			else {
				list.push_back(input);
			}
		}

	}

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << "\n";
	}

	return 0;
}