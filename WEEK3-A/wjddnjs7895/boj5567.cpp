#include <iostream>
#include <queue>
using namespace std;

int N, M, counting = 0;
bool arr[501][501];
int visited[501] = { 0, };

void bfs() {
	queue<int> Q;
	visited[1] = 1;
	for (int i = 1; i <= N; i++) {
		if (arr[1][i] == 1) {
			if (!visited[i]) {
				Q.push(i);
				visited[i] = 1;
				counting += 1;
			}
		}
	}
	while (!Q.empty()) {
		int n = Q.front();
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[n][i] == 1) {
				if (!visited[i]) {
					visited[i] = 1;
					counting += 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	bfs();
	printf("%d\n", counting);
}