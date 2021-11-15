#include<iostream>
#include<vector>

std::vector<int> Factorization(int N) {
	std::vector<int> value;

	int div = 2;

	while (div <= N)
	{
		if (N % div == 0) {
			value.push_back(div);
			N /= div;
		}
		else {
			div++;
		}
	}

	return value;

}

int main() {

	using namespace std;

	int N;
	cin >> N;
	
	vector<int> factor = Factorization(N);
	
	for (int i = 0; i < factor.size(); i++) {
		cout << factor[i] << "\n";
	}

	return 0;
}