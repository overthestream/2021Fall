#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M, flag, counting, result = INT_MAX;
int arr[10][10], temp_arr[10][10];

void change(int x, int y) {
	int d[3] = { -1, 0, 1 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x + d[i] > 0 && x + d[i] <= N && y + d[j] > 0 && y + d[j] <= M) {
				if (arr[x + d[i]][y + d[j]])
					arr[x + d[i]][y + d[j]] = 0;
				else
					arr[x + d[i]][y + d[j]] = 1;
			}
		}
	}
	counting += 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char temp;
			cin >> temp;
			if (temp == '*') {
				arr[i][j] = 1;
				temp_arr[i][j] = 1;
			}
			else {
				arr[i][j] = 0;
				temp_arr[i][j] = 0;
			}
		}
	}
	for (int x = 0; x < (1 << N); x++) {
		for (int y = 0; y < (1 << M); y++) {
			flag = 1, counting = 0;
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= M; j++)
					arr[i][j] = temp_arr[i][j];

			for (int i = 0; i < N; i++) {
				if (x & (1 << i))
					change(i + 1, 1);
			}
			for (int j = 0; j < M; j++) {
				if (y & (1 << j))
					change(1, j + 1);
			}

			for (int i = 2; i <= N; i++) {
				for (int j = 2; j <= M; j++) {
					if (!arr[i - 1][j - 1]) {
						change(i, j);
					}
				}
			}
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (!arr[i][j])
						flag = 0;
				}
			}
			if (flag) {
				result = min(result, counting);
			}
		}
	}

	if (result != INT_MAX)
		printf("%d\n", result);
	else
		printf("-1\n");
}