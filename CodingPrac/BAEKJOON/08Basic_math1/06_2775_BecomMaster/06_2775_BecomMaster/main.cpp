#include <iostream>
#include <string>
#include <vector>


int main() {

	using namespace std;
	
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int k, n;
		cin >> k >> n;

		int val = 0;

		if (k == 0) {
			val = n;
			continue;
		}

		vector<int> floor;
		for (int j = 1; j <= n; j++) {
			floor.push_back(j);
		}

		for (int i2 = 1; i2 <= k; i2++) {
			vector<int> temp;
			
			for (int i3 = 0; i3 < floor.size(); i3++) {
				int sum = 0;
				for (int i4 = 0; i4 <= i3; i4++) {
					sum += floor[i4];
				}
				temp.push_back(sum);
			}
			
			floor.clear();
			floor.assign(temp.begin(), temp.end());
		}
		
		val = *(--floor.end());
		cout << val << "\n";
	}


	return 0;
}