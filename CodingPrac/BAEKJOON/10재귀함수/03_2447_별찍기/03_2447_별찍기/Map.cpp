#include "Map.h"

int Map::getMapSize() {
	return this->map_size;
}

void Map::setMapSize(int size) {
	this->map_size = size;
	return;
}

void Map::makeMap() {
	this->map = " ";
	for (int i = 0; i < this->map_size * this->map_size; i++) {
		map += "*";
	}
	return;
}

int Map::getK() {
	return this->k;
}

void Map::setK(int k) {
	this->k = k;
	return;
}

void Map::printMap() {
	for (int i = 1; i < this->map.size(); i++) {
		std::cout << this->map[i];
		if (i % this->map_size == 0) {
			std::cout << "\n";
		}
	}
	return;
}

void Map::eraseStar(int x, int y) {
	this->map[(y - 1) * this->map_size + x] = ' ';
	return;
}

void Map::setEmptyBox(int x, int y, int size) {
	for (int i = y - size; i <= y + size; i++) {
		for (int j = x - size; j <= x + size; j++) {
			this->eraseStar(i, j);
		}
	}
	return;
}

void Map::setMap(int k) {
	
	if (k < 1) {
		return;
	}

	int n1 = 0;
	int n2 = 0;
	int diff = pow(3, k - 1) / 2;

	while (true)
	{
		int referValueY = pow(3, k) * n2 + pow(3, k) / 2 + 1;

		if (referValueY + diff > this->map_size) {
			break;
		}

		while (true)
		{
			int referValueX = pow(3, k) * n1 + pow(3, k) / 2 + 1;

			if (referValueX + diff > this->map_size) {
				break;
			}

			this->setEmptyBox(referValueX, referValueY, diff);

			n1++;
		}

		n1 = 0;
		n2++;
		
	}
	
	this->setMap(k - 1);
	
	return;

}