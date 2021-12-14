#include<iostream>
#include<cmath>

int main() {

	using namespace std;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << "\n";
			continue;
		}

		double L = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		int AB = r1 + r2;

		if (L < r1 || L < r2) {
			int l, s;
			if (r1 > r2) {
				l = r1;
				s = r2;
			}
			else {
				l = r2;
				s = r1;
			}

			if (L + s < l) {
				cout << 0 << "\n";
			}
			else if (L + s == l) {
				cout << 1 << "\n";
			}
			else {
				cout << 2 << "\n";
			}

		}
		else {
			if (L < AB) {
				cout << 2 << "\n";
			}
			else if (L == AB) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
	}


	return 0;
}