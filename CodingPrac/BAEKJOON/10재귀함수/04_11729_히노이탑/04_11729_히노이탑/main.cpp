#include<iostream>
#include<vector>

void hinoi(int N, int from, int to, int other, std::vector<std::vector<int>> &moveLog);
int main() {
	
	using namespace std;

	int N;
	cin >> N;

	vector<vector<int>> moveLog;

	hinoi(N, 1, 3, 2, moveLog);

	cout << moveLog.size() << "\n";
	for (int i = 0; i < moveLog.size(); i++) {
		cout << moveLog[i][0] << " " << moveLog[i][1] << "\n";
	}

	return 0;
}

void hinoi(int N, int from, int to, int other, std::vector<std::vector<int>>& moveLog) {

	if (N == 1) {
		
		std::vector<int> log = { from, to };
		moveLog.push_back(log);

		return;
	}

	hinoi(N - 1, from, other, to, moveLog);
	
	std::vector<int> log2 = { from, to };
	moveLog.push_back(log2);

	hinoi(N -1, other, to , from, moveLog);
	return;
}