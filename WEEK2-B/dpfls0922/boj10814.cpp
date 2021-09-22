#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}
int main() {
	int tc;
	cin >> tc;

	vector<pair<int, string>> info(tc);

	for (int i = 0; i < tc; i++) 
		cin >> info[i].first >> info[i].second;

	stable_sort(info.begin(), info.end(), compare);
	
	for (int i=0; i<tc; i++)
		cout << info[i].first << ' ' << info[i].second << '\n';
	return 0;
}