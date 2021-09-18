#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, L;
	cin >> N >> L;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		PQ.push({ num, i });
		while (PQ.top().second <= i - L)
			PQ.pop();
		cout << PQ.top().first << ' ';
	}
}