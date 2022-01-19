#include<iostream>
#include<memory.h>

#include<string>

int main() {

	using namespace std;
	
	/* c �� c++������� ����ȭ�� �����Ͽ� ������� �ӵ��� ���δ�.
	������ c �� ����°� ȥ���ؼ� ������� �� ��.
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int countArr[10001];
	memset(countArr, 0, sizeof(int) * 10001);

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		countArr[input]++;
		
	}

	
	for (int i = 0; i < 10001; i++) {
		string result = "";
		for (int j = 0; j < countArr[i]; j++) {
			result += to_string(i) + "\n";
			if (j % 10000 == 9999) {
				cout << result;
				result = "";
			}
		}
		cout << result;
	}

	return 0;
}