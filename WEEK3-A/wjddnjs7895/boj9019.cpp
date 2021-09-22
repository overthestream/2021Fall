#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
int a, b, temp;
bool visited[10000] = { 0, };

string bfs() {
	for (int i = 0; i < 10000; i++)
		visited[i] = 0;
	queue<pair<int, string>> Q;
	Q.push({ a, "" });
	visited[a] = 1;
	while (!Q.empty()) {
		pair<int, string> n = Q.front();
		Q.pop();
		if (n.first == b)
			return n.second;

		temp = n.first * 2 % 10000;
		if (!visited[temp]) {
			Q.push({ temp,n.second + "D" });
			visited[temp] = 1;
		}

		if (n.first == 0)
			temp = 9999;
		else
			temp = n.first - 1;
		if (!visited[temp]) {
			Q.push({ temp,n.second + "S" });
			visited[temp] = 1;
		}

		temp = (n.first % 1000) * 10 + n.first / 1000;
		if (!visited[temp]) {
			Q.push({ temp,n.second + "L" });
			visited[temp] = 1;
		}

		temp = (n.first % 10) * 1000 + (n.first / 10);
		if (!visited[temp]) {
			Q.push({ temp,n.second + "R" });
			visited[temp] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << bfs() << endl;
	}
}