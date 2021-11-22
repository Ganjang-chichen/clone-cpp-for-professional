#include <iostream>

int main() {

	using namespace std;
	int Ax, Ay, Bx, By, Cx, Cy;

	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;

	int X, Y;

	if (Ax == Bx) {
		if (Ay == Cy) {
			X = Cx;
			Y = By;
		}
		else if (By == Cy) {
			X = Cx;
			Y = Ay;
		}
	}
	else if (Ax == Cx) {
		if (Ay == By) {
			X = Bx;
			Y = Cy;
		}
		else if (By == Cy) {
			X = Bx;
			Y = Ay;
		}
	}
	else if (Bx == Cx) {
		if (Ay == By) {
			X = Ax;
			Y = Cy;
		}
		else if (Ay == Cy) {
			X = Ax;
			Y = By;
		}
	}

	cout << X << " " << Y;

	return 0;
}