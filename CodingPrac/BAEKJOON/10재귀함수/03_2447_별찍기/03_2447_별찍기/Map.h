#pragma once
#include<iostream>
#include<string>
#include<cmath>

class Map
{
private :
	std::string map = " ";
	int map_size = 3;
	int k = 0;
	void setEmptyBox(int x, int y, int size);
	void eraseStar(int x, int y);
	

public :

	void makeMap();
	void printMap();
	void setMap(int k);

	int getK();
	void setK(int k);

	int getMapSize();
	void setMapSize(int size);
};

