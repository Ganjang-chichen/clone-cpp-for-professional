#include<iostream>
#include<vector>
#include<string>

int main() {

	using namespace std;

	int N = 0;
	cin >> N;

	int x, y;
	cin >> x >> y;

	vector<int> axisList = {x, y};

	for (int i = 0; i < N - 1; i++) {
		
		cin >> x >> y;
		if (x < axisList[0] ||
			(x <= axisList[0] && y <= axisList[1])) {
			axisList.insert(axisList.begin(), y);
			axisList.insert(axisList.begin(), x);

			cout << 1 << "\n";
		}
		else if (axisList[axisList.size() - 2] < x ||
			(axisList[axisList.size() - 2] <= x && axisList[axisList.size() - 1] <= y)) {
			axisList.push_back(x);
			axisList.push_back(y);

			cout << 2 << "\n";
		}
		else {

			int buff = 0;
			while (true)
			{
				if (axisList[2 * buff] < x && x < axisList[2 * (buff + 1)]) {	// x0 < x1 < x2
					axisList.insert(axisList.begin() + 2 * (buff + 1), y);
					axisList.insert(axisList.begin() + 2 * (buff + 1), x);
					
					cout << 3 << "\n";

					break;
				}

				else if (axisList[2 * buff] == x && x < axisList[2 * (buff + 1)]) {	// x0 == x1 < x2
					if (axisList[2 * buff + 1] <= y) {
						axisList.insert(axisList.begin() + 2 * (buff + 1), y);
						axisList.insert(axisList.begin() + 2 * (buff + 1), x);
						
						cout << 4 << "\n";

						break;
					}
				}
				
				else if (axisList[2 * buff] < x && x == axisList[2 * (buff + 1)]) {	// x0 < x1 == x2
					if (y <= axisList[2 * (buff + 1) + 1]) {
						axisList.insert(axisList.begin() + 2 * (buff + 1), y);
						axisList.insert(axisList.begin() + 2 * (buff + 1), x);
						
						cout << 5 << "\n";
						
						break;
					}
				}

				else if (axisList[2 * buff] == x && x == axisList[2 * (buff + 1)]) {	// x0 == x1 == x2
					if (axisList[2 * buff + 1] <= y && y <= axisList[2 * (buff + 1) + 1]) {
						axisList.insert(axisList.begin() + 2 * (buff + 1), y);
						axisList.insert(axisList.begin() + 2 * (buff + 1), x);

						cout << 6 << "\n";

						break;
					}
				}

				buff++;
			}

		}
		
	}

	string result = "";
	for (int i = 0; i < axisList.size() / 2; i++) {
		cout << axisList[2 * i] << " " << axisList[2 * i + 1] << "\n";
		result += to_string(axisList[2 * i]) + " " + to_string(axisList[2 * i + 1]) + "\n";
	}

	return 0;
}
