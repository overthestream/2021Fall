#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	int num;
	cin >> num;

	vector<pair<int, string>> array(num);

	for (int i = 0; i < num; i++)
		cin >> array[i].first >> array[i].second;

	stable_sort(array.begin(), array.end(), compare);

	for (int i = 0; i < num; i++)
		cout << array[i].first << " " << array[i].second << endl;
}