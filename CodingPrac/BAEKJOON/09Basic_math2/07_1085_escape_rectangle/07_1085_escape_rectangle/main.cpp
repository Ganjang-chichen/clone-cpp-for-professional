#include <iostream>

int main() {

	using namespace std;

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int distance_XS = x;
	int distance_XL = w - x;
	int distance_YS = y;
	int distance_YL = h - y;

	int min = 0;
	if (distance_XS > distance_XL) {
		min = distance_XL;
	}
	else {
		min = distance_XS;
	}

	if (min > distance_YL) {
		min = distance_YL;
	}
	if (min > distance_YS) {
		min = distance_YS;
	}

	cout << min;

	return 0;
}