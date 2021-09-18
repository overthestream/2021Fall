#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, MIN = 1000000;
int arr[1001][1001];
int visited[1001][1001][2];

int bfs() {
	queue<pair<pair<int, int>, int>> Q;
	Q.push({ { 0,0 },1 });
	visited[0][0][0] = 1;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int size = Q.size();
	while (!Q.empty()) {
		int x = Q.front().first.first / M;
		int y = Q.front().first.first % M;
		int num = Q.front().first.second;
		int counting = Q.front().second;
		Q.pop();
		if (x == N - 1 && y == M - 1)
			return counting;
		size -= 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (arr[nx][ny] == 1 && num == 0 && !visited[nx][ny][1]) {
					Q.push({ { nx * M + ny, 1 },counting + 1 });
					visited[nx][ny][1] = 1;
				}
				else if (arr[nx][ny] == 0) {
					if (num == 0 && !visited[nx][ny][0]) {
						Q.push({ { nx * M + ny, num },counting + 1 });
						visited[nx][ny][0] = 1;
					}
					else if (num == 1 && !visited[nx][ny][1]) {
						Q.push({ { nx * M + ny, num },counting + 1 });
						visited[nx][ny][1] = 1;
					}
				}
			}
		}
	}
	return 1000000;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &arr[i][j]);
	MIN = min(MIN, bfs());
	if (MIN == 1000000)
		printf("-1\n");
	else
		printf("%d\n", MIN);
}