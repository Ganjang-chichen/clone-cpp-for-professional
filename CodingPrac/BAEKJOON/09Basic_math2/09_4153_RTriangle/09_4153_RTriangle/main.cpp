#include <iostream>

int main() {

	using namespace std;

	while (true){
		int A, B, C;
		cin >> A >> B >> C;

		if (A == 0 && B == 0 && C == 0) {
			break;
		}

		bool isRTriangle = false;
		if (A > B && A > C) {
			if ((A * A) == (B * B + C * C)) {
				isRTriangle = true;
			}
		}
		if (B > A && B > C) {
			if ((B * B) == (A * A + C * C)) {
				isRTriangle = true;
			}
		}
		if (C > B && C > A) {
			if ((C * C) == (B * B + A * A)) {
				isRTriangle = true;
			}
		}

		if (isRTriangle) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}

	}

	return 0;
}