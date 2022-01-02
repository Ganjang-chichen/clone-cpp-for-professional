#include<iostream>
#include<vector>

int checkBox(const std::vector<std::vector<char>> &chessMap, int x, int y);

int main() {

	using namespace std;

	int N, M;
	cin >> N >> M;

	vector<vector<char>> chessMap;

	for (int i = 0; i < N; i++) {

		vector<char> line;

		for (int j = 0; j < M; j++) {
			char block;
			cin >> block;
			line.push_back(block);
		}

		chessMap.push_back(line);

	}

	int min = 2500;

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int boxCount = checkBox(chessMap, j, i);
			if (min > boxCount) {
				min = boxCount;
			}
		}
	}

	cout << min;

}

int checkBox(const std::vector<std::vector<char>> &chessMap, int x, int y) {

	char baseBlock = chessMap[y][x];

	int count_case1 = 0;
	int count_case2 = 0;

	for (int i = y; i < y + 8; i++) {

		for (int j = x; j < x + 8; j++) {

			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (chessMap[i][j] != baseBlock) {
						count_case1++;
					}
					else {
						count_case2++;
					}
				}
				else {
					if (chessMap[i][j] == baseBlock) {
						count_case1++;
					}
					else {
						count_case2++;
					}
				}
			}
			else {
				if (j % 2 == 0) {
					if (chessMap[i][j] == baseBlock) {
						count_case1++;
					}
					else {
						count_case2++;
					}
				}
				else {
					if (chessMap[i][j] != baseBlock) {
						count_case1++;
					}
					else {
						count_case2++;
					}
				}
			}
		}

	}

	if (count_case1 > count_case2) {
		return count_case2;
	}
	else {
		return count_case1;
	}
}
