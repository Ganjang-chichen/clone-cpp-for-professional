#include<iostream>
#include<string>
#include<cmath>

int main() {

	using namespace std;

	string A, B;
	cin >> A >> B;

	int A_Size = A.size() - 1;
	int B_Size = B.size() - 1;

	string value = "";

	int overflow = 0;
	while (A_Size >= 0 || B_Size >= 0 || overflow == 1) {
		if (A_Size < 0 && B_Size < 0) {
			value = "1" + value;
			break;
		}
		
		int merge;
		if (A_Size < 0) {
			merge = overflow + (int)B[B_Size];
		}
		else if (B_Size < 0) {
			merge = overflow + (int)A[A_Size];
		}
		else {
			merge = overflow + (int)A[A_Size] + (int)B[B_Size] - 48;

		}

		if (merge - 48 > 9) {
			merge = merge - 10;
			overflow = 1;
		}
		else {
			overflow = 0;
		}
		value = (char)merge + value;

		A_Size--;
		B_Size--;
	}

	cout << value;

	return 0;
}