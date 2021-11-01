#include<iostream>

int main() {

	using namespace std;

	int X;
	cin >> X;

	int IDX = 0;
	int sum = 0;
	while (true) {
		sum += IDX;
		if (sum >= X) {
			break;
		}
		IDX++;
	}
	int move = X - (sum - IDX) - 1;
	int head;
	int bottom;
	if (IDX % 2 == 0) {
		head = 1 + move;
		bottom = IDX - move;
	}
	else {
		head = IDX - move;
		bottom = 1 + move;
	}
	
	cout << head << "/" << bottom;

	return 0;
}