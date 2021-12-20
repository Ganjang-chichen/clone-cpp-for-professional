#pragma once

#include "Map.h"

int main() {

	using namespace std;

	int N;
	cin >> N;

	int k = 0;
	while (true) {
		if (pow(3, k) == N) {
			break;
		}
		k++;
	}

	Map test;

	test.setK(k);
	test.setMapSize(N);
	test.makeMap();
	test.setMap(k);
	test.printMap();

	return 0;
}

