#include <iostream>
#include <string>

int main() {

	using namespace std;
	int kg;
	cin >> kg;

	if (kg < 3) {
		cout << -1;
		return 0;
	}

	if (kg == 4 || kg == 7) {
		cout << -1;
		return 0;
	}

	int start = kg / 5;
	while (start >= 0){

		for (int i = 0; ; i++) {
			int val = start * 5 + i * 3;

			if (val > kg) {
				break;
			}
			if (val == kg) {
				cout << start + i << "\n";
				return 0;
			}

		}
		start--;
	}

	cout << -1;
	return 0;
}
