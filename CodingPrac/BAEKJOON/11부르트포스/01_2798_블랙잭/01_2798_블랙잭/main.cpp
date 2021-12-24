#include<iostream>
#include<vector>

int main() {

	using namespace std;

	int N, M;
	cin >> N >> M;

	vector<int> cardList;

	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		cardList.push_back(card);
	}

	int min = 300000;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {

				int diff = M - (cardList[i] + cardList[j] + cardList[k]);

				if (diff >= 0 && diff < min) {
					min = diff;
				}

			}
		}
	}

	cout << M - min << "\n";

	return 0;
}