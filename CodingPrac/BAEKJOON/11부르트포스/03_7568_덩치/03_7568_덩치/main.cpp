#include<iostream>
#include<vector>



int main() {

	using namespace std;

	int N;
	cin >> N;
	
	vector<vector<int>> peopleList;
	for (int i = 0; i < N; i++) {
		int weight, height;
		cin >> weight >> height;
		vector<int> peopleInfo = { weight, height };
		peopleList.push_back(peopleInfo);
	}
	
	vector<vector<int>> orderedList;

	return;
}

void sortList(std::vector<std::vector<std::vector<int>>> &orderedList, std::vector<int> newList) {
	
	int point = 0;
	while (true)
	{
		bool status = false;
		for (int i = 0; i < orderedList[point].size(); i++) {
			if (orderedList[point][i][0] > newList[0] && orderedList[point][i][1] > newList[1]) {
				std::vector<std::vector<int>> temp;
				temp.push_back(newList);
				orderedList.insert(orderedList.begin() + point, temp);
				
				status = true;
				break;
			}
			else if (orderedList[point][i][0] < newList[0] && orderedList[point][i][1] < newList[1]) {
				point++;
			}
			else {
				orderedList[point].push_back(newList);
				status = true;
				break;
			}
		}
		if (!status) {
			std::vector<std::vector<int>> temp;
			temp.push_back(newList);
			orderedList.push_back(temp);
		}
	}

}