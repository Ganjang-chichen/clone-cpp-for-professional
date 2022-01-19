#include<iostream>
#include<vector>
#include<memory.h>
#include<cmath>

int main() {

	using namespace std;

	int N;
	cin >> N;
	
	int countArr[8001]; // -4000 ~ 4000
	memset(countArr, 0, sizeof(int) * 8001);
	int sum = 0;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		sum += input;

		input += 4000;
		countArr[input]++;
	}
	//************************************************** »ê¼úÆò±Õ

	cout << round((double)sum / N) << "\n"; 

	//************************************************** Áß¾Ó°ª

	int middle_idx = 0;
	int count_idx = 0;

	while (count_idx < N / 2 + 1) {
		count_idx += countArr[middle_idx];
		middle_idx++;
	}

	cout << middle_idx - 4000 - 1 << "\n";

	//************************************************** ÃÖºó°ª, ¹üÀ§

	int max_frequency = 0;

	for (int i = 0; i < 8001; i++) {
		if (max_frequency < countArr[i]) {
			max_frequency = countArr[i];
		}
	}

	int start_list = 0;
	bool is_started = false;
	int end_list = 0;
	vector<int> max_frequency_list;

	for (int i = 0; i < 8001; i++) {

		if (max_frequency == countArr[i]) {
			max_frequency_list.push_back(i);
		}

		if (!is_started && countArr[i] != 0) {
			start_list = i;
			is_started = true;
		}

		if (countArr[i] != 0) {
			end_list = i;
		}
		
	}

	if (max_frequency_list.size() > 1) {
		cout << max_frequency_list[1] - 4000 << "\n";
	}
	else {
		cout << max_frequency_list[0] - 4000 << "\n";
	}

	cout << end_list - start_list << "\n";

	//**************************************************
}