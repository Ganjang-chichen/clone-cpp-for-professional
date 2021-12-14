#include<iostream>

#define _USE_MATH_DEFINES
#include<math.h>

int main() {

	using namespace std;

	int R;
	cin >> R;

	cout << fixed;
	cout.precision(5);

	cout << M_PI * R * R << "\n";
	cout << 2 * R * R << "\n";

}