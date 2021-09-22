#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool between(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}
int main() {
	int input[10];
	int count;

	cin >> count;

	pair<int, string> tmp;
	vector<pair<int, string>> array;
	for (int i = 0; i < count; i++) {
		cin >> tmp.first >> tmp.second;
		array.push_back(tmp);
	}
	stable_sort(array.begin(), array.end(), between);
	for (int i = 0; i < count; i++) {
		cout << array[i].first << ' ' << array[i].second << endl;
	}
}