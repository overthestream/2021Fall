#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, rarr[8][8], arr[8][8], MAX = 0;
queue<pair<int, int>> Q;
queue<pair<int, int>> RQ;

int count() {
	int counting = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 0)
				counting += 1;
	return counting;
}

int bfs() {
	Q = RQ;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0) {
				Q.push({ nx, ny });
				arr[nx][ny] = 2;
			}
		}
	}
	int result = count();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = rarr[i][j];
	return result;
}

void backtrack() {
	for (int i = 0; i < N * M - 2; i++) {
		for (int j = i + 1; j < N * M - 1; j++) {
			for (int k = j + 1; k < N * M; k++) {
				int ix = i / M;
				int iy = i % M;
				int jx = j / M;
				int jy = j % M;
				int kx = k / M;
				int ky = k % M;
				if (arr[ix][iy] == 0 && arr[jx][jy] == 0 && arr[kx][ky] == 0) {

					arr[ix][iy] = 1;
					arr[jx][jy] = 1;
					arr[kx][ky] = 1;
					MAX = max(bfs(), MAX);
					arr[ix][iy] = 0;
					arr[jx][jy] = 0;
					arr[kx][ky] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> rarr[i][j];
			arr[i][j] = rarr[i][j];
			if (arr[i][j] == 2)
				RQ.push({ i,j });
		}
	}
	backtrack();
	printf("%d\n", MAX);
}