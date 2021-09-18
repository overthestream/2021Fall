#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}