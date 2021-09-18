#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int input[10];
	int test;

	cin >> test;

	for (int i = 0; i < test; i++) {
		for (int i = 0; i < 10; i++) {
			cin >> input[i];
		}
		sort(input, input + 10);
		cout << input[7] << endl;
	}
}