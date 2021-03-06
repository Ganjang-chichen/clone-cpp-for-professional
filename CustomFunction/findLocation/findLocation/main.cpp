#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<time.h>

std::string input = R"(    
    
##  )";

bool isMultiple(int num, int param) {
	int temp = 1;
	
	bool isTrue = false;

	while (temp * param <= abs(num)) {
		if (temp * param == abs(num)) {
			isTrue = true;
			break;
		}
		temp++;
	}

	return isTrue;
}



void show_vector_int(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}

void show_Vector_Map(std::vector<std::vector<int>> v) {
	std::cout << "     ";
	for (int i = 0; i < v.size(); i++) {
		std::cout << i % 10 << "    ";
	}
	std::cout << "\n";
	for (int i = 0; i < v.size(); i++) {
		std::cout << i % 10 << " : ";
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] < 0) {
				std::cout << v[i][j] << " | ";
			}
			else {
				std::cout << " " << v[i][j] << " | ";
			}
			
		}
		std::cout << "\n";
	}
	return;
}

std::string make_wall(std::string& map, int row, int column, char block) {
	std::string value = "";
	for (int i = 0; i < column + 2; i++) {
		value += block;
	}
	value = value + "\n" + block;

	for (int i = 0; i < map.size(); i++) {
		if (map[i] == '\n') {
			value = value + block + "\n" + block;
		}
		else {
			value += map[i];
		}
	}
	value = value + block + "\n";

	for (int i = 0; i < column + 2; i++) {
		value += block;
	}

	return value;
}

std::vector<std::vector<int>> make_weight_default(std::string map, int row, int column, char block) {

	std::vector<std::vector<int>> value;
	for (int i = 0; i < row * column; i++) {
		std::vector<int> temp;

		for (int j = 0; j < row * column; j++) {
			temp.push_back(-1);
		}

		value.push_back(temp);
	}

	int col_count = 0;
	int row_count = 0;
	for (int i = 0; i < map.size(); i++) {
		if (map[i] == '\n') {
			row_count++;
			col_count = 0;
			continue;
		}

		if (map[i] != block) {

			if (map[i - column - 1] != block) {
				value[(row_count - 1) * column + col_count][row_count * column + col_count] = 1;
			}
			if (map[i + column + 1] != block) {
				value[(row_count + 1) * column + col_count][row_count * column + col_count] = 1;
			}
			if (map[i + 1] != block) {
				value[row_count * column + col_count + 1][row_count * column + col_count] = 1;
			}
			if (map[i - 1] != block) {
				value[row_count * column + col_count - 1][row_count * column + col_count] = 1;
			}

		}

		col_count++;
	}

	return value;
}

std::vector<std::vector<int>> DFS(std::vector<std::vector<int>> weight, int start, int end) {
	
	std::vector<std::vector<int>> values;
	std::vector<std::vector<int>> stack;
	std::vector<std::vector<int>> temp_stack;
	std::vector<int> start_v;
	start_v.push_back(start);
	stack.push_back(start_v);
	while (true){

		if (stack.size() == 0) {
			break;
		}

		for (int i = 0; i < stack.size(); i++) {
			int leaf = stack[i][stack[i].size() - 1];

			for (int j = 0; j < weight.size(); j++) {
				
				if (weight[leaf][j] == 1) {
					

					bool isVisited = false;
					for (int k = 0; k < stack[i].size(); k++) {
						if (stack[i][k] == j) {
							isVisited = true;
						}
					}
					if (!isVisited) {
						
						std::vector<int> temp;
						temp.resize(stack[i].size());
						std::copy(stack[i].begin(), stack[i].end(), temp.begin());
						temp.push_back(j);

						if (j == end) {

							if (values.size() == 0) {
								values.push_back(temp);
							}
							else if (values[0].size() == temp.size()) {
								values.push_back(temp);
							}
							else if (values[0].size() > temp.size()) {
								values.clear();
								values.push_back(temp);
							}

						}
						else {

							if (values.size() == 0) {
								temp_stack.push_back(temp);
							}
							else if (values[0].size() > temp.size()) {
								temp_stack.push_back(temp);
							}
						}

					}
					
				}
			}
		}

		stack.clear();
		stack.resize(temp_stack.size());
		std::copy(temp_stack.begin(), temp_stack.end(), stack.begin());
		temp_stack.clear();
	}

	return values;
}


int main() {

	using namespace std;

	// https://scarlettb.tistory.com/5 ?????? ????????
	clock_t start, finish;
	double duration;

	start = clock();
	/*???? ?????? ???????? ???? ????*/
	
	//vector<vector<int>> v = make_weight_default(input, 5, 8, '#');
	//show_Vector_Map(v);


	string cmap = make_wall(input, 3, 4, '#');

	cout << cmap << "\n";

	vector<vector<int>> v = make_weight_default(cmap, 5, 6, '#');
	show_Vector_Map(v);

	vector<vector<int>> test = DFS(v, 16, 7);

	for (int i = 0; i < test.size(); i++) {
		for (int j = 0; j < test[i].size(); j++) {
			cout << test[i][j] << " ";
		}
		cout << "\n";
	}

	if (test.empty()) {
		cout << "can not find load";
	}

	

	/*************??*****************/
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << duration << "??" << "\n";


	return 0;
}