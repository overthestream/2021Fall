#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int count;
	cin >> count;

	vector<int> array;
	int input;

	for (int i = 0; i < count; i++) {
		cin >> input;
		array.push_back(input);
	}

	sort(array.begin(), array.end());

	array.erase(unique(array.begin(), array.end()), array.end());

	for (auto i : array) {
		cout << i << " ";
	}
}