#include<iostream>


int main() {
	
	using namespace std;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		unsigned int x, y;
		cin >> x >> y;
		unsigned int L = y - x;

		if (L == 1) {
			cout << 1 << "\n";
			continue;
		}

		int count = 2;
		unsigned int maxL = 2;
		while (true) {
			
			maxL += count / 2 + 1;

			if (maxL >= L) {
				cout << count + 1 << "\n";
				break;
			}

			count++;
		}

	}
	
	return 0;
}