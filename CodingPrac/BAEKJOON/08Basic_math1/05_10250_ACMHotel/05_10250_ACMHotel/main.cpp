#include <iostream>
#include <string>


int main() {

	using namespace std;
	int n;
	cin >> n;
	for (int i = 0;i < n; i++) {
		int H, W, N;
		cin >> H >> W >> N;

		int col = N / H;
		int row = N % H;
		
		if (row == 0) {
			row = H;
		}
		else {
			col++;
		}

		int val = row * 100 + col;
		cout << val << "\n";
	}
	
	return 0;
}