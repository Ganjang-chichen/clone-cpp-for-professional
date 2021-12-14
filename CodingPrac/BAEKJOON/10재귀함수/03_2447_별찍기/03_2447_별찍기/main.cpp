#include<iostream>
#include<string>

int main() {

	using namespace std;

	int N;
	cin >> N;

	string map = "";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map += "*";
		}
		map += "\n";
	}

	return 0;
}

void erasePoint(std::string m, int N) {

	erasePoint(m, N / 3);
	return;
}