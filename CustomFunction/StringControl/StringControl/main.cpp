#include<iostream>
#include<string>
#include<vector>
#include<time.h>

// show vector<string>
void show_Vector_String(std::vector<std::string>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << "/";
	}
	std::cout<< " size : " << v.size() << "\n";
	return;
}
// show vector<int>
void show_Vector_Int(std::vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << "/";
	}
	std::cout << " size : " << v.size() << "\n";
	return;
}

// string split
std::vector<std::string> string_split(std::string& str, std::string& ditribute) {
	std::vector<std::string> value;

	if (str.size() < ditribute.size()) {
		return value;
	}
	if (ditribute == "") {
		return value;
	}

	int i = 0;
	bool isSame = true;
	int start = 0;

	while (true) {

		if (str.size() < i + ditribute.size()) {
			std::string temp = "";
			for (int j = start; j < str.size(); j++) {
				temp += str[j];
			}
			if (temp != ditribute && temp != "") {
				value.push_back(temp);
			}
			break;
		}

		isSame = true;
		for (int j = 0; j < ditribute.size(); j++) {
			if (str[i + j] != ditribute[j]) {
				isSame = false;
				break;
			}
		}
		if (isSame) {
			std::string temp = "";
			for (int j = start; j < i; j++) {
				temp += str[j];
			}

			if (temp != ditribute && temp != "") {
				value.push_back(temp);
			}
			i += ditribute.size();
			start = i;
		}
		else {
			i++;
		}
	}

	return value;
}

//string convert. ex: ("abcdef", "cd", "aa") -> "abaaef"
std::string string_convert(std::string& str, std::string& from, std::string& to) {

	int i = 0;
	int start = 0;
	bool isSame = true;
	std::string value = "";

	while (i < str.size()){

		if (str.size() < i + from.size()) {
			value += str[i];
			i++;
			continue;
		}

		isSame = true;
		for (int j = 0; j < from.size(); j++) {
			if (str[i + j] != from[j]) {
				isSame = false;
				break;
			}
		}
		
		if (isSame) {
			value += to;
			i += from.size();
		}
		else {
			value += str[i];
			i++;
		}
		
	}

	return value;

}

//string convert by int idx, idx must be sorted.
std::string string_convert_idx(std::string& str, std::string& from, std::string& to, std::vector<int>& idx) {

	if (idx.size() == 0) {
		return str;
	}

	int i = 0;
	int start = 0;
	int count_str = 0;
	int count_idx = 0;
	bool isSame = true;
	std::string value = "";

	while (i < str.size()) {

		if (str.size() < i + from.size()) {
			value += str[i];
			i++;
			continue;
		}

		isSame = true;
		for (int j = 0; j < from.size(); j++) {
			if (str[i + j] != from[j]) {
				isSame = false;
				break;
			}
		}
		
		if (isSame && count_str == idx[count_idx]) {
			value += to;
			i += from.size();

			if (count_idx < idx.size() - 1) {
				count_idx++;
			}

		}
		else {
			value += str[i];
			i++;
		}

		if (isSame) {
			count_str++;
		}

	}

	return value;

}

//return param's location by vector<int> ex: ("a  a a   a", "  ") -> {1, 6}
std::vector<int> string_include(std::string& str, std::string& param) {

	std::vector<int> value;

	int i = 0;
	bool isSame = true;

	while (true) {

		if (str.size() < i + param.size()) {
			break;
		}

		isSame = true;
		for (int j = 0; j < param.size(); j++) {
			if (str[i + j] != param[j]) {
				isSame = false;
				break;
			}
		}
		
		if (isSame) {
			value.push_back(i);
			i += param.size();
		}
		else {
			i++;
		}

	}

	return value;
}

int main() {

	using namespace std;

	// https://scarlettb.tistory.com/5 타이머 예제코드
	clock_t start, finish;
	double duration;

	start = clock();

	/*실행 시간을 측정하고 싶은 코드*/

	/* 실행 예제

	string str = "we are pretent to be       pretent    gsrgs  pretent   ";
	string from = "  ";
	string to = "&";
	vector<int> idx = {1, 3, 100};
	cout << string_convert_idx(str, from, to, idx) << "\n";

	vector<string> v = string_split(str, from);
	show_Vector_String(v);

	vector<int> v2 = string_include(str, from);
	show_Vector_Int(v2);

	*/
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << duration << "초" << "\n";
	
	return 0;
}