#include<iostream>
#include<vector>

bool isContain666(int n);

int main() {

	using namespace std;

	int N;
	cin >> N;

	int count = 0;
	
	for (int i = 666;; i++) {
		if (isContain666(i)) {
			count++;
		}
		if (count == N) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}

bool isContain666(int n) {
	
	if (n < 666) {
		return false;
	}
	
	int temp = n;
	while (temp > 0)
	{

		if(temp % 1000 == 666){
			return true;
		}
		
		temp /= 10;

	}

	return false;

}