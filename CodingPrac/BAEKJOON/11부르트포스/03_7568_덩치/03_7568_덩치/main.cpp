#include<iostream>
#include<vector>

void countBiggerPeople(std::vector<std::vector<int>>& peopleList);

int main() {

	using namespace std;

	int N;
	cin >> N;
	
	vector<vector<int>> peopleList;
	for (int i = 0; i < N; i++) {
		int weight, height;
		cin >> weight >> height;
		vector<int> peopleInfo = { weight, height, 1 };
		peopleList.push_back(peopleInfo);
	}
	
	

	countBiggerPeople(peopleList);

	for (int i = 0; i < peopleList.size(); i++) {
		cout << peopleList[i][2] << " ";
	}

	return 0;
}

void countBiggerPeople(std::vector<std::vector<int>> &peopleList) {

	for (int i = 0; i < peopleList.size(); i++) {
		for (int j = 0; j < peopleList.size(); j++) {

			if (peopleList[i][0] < peopleList[j][0] && peopleList[i][1] < peopleList[j][1]) {
				peopleList[i][2]++;
			}
		}
	}

	return;
}
