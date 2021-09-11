#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N;
long long arr[21][21], MAX = 0;


void move(int dir) {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	for (int i = 0; i < N; i++) {
		deque<long long> DQ;
		int x = i, y = i;
		if (dir == 1)
			x = N - 1;
		else if (dir == 3)
			y = N - 1;
		else if (dir == 2)
			y = 0;
		else
			x = 0;
		int nx = x, ny = y;

		while (true) {
			if (x < 0 || y < 0 || x > N - 1 || y > N - 1)
				break;
			if (nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1) {
				break;
			}
			if (arr[nx][ny]) {
				if ((nx != x || ny != y) && arr[nx][ny] == arr[x][y]) {
					DQ.pop_back();
					DQ.push_back(arr[nx][ny] * 2);
					x = nx + dx[dir];
					y = ny + dy[dir];
				}
				else {
					DQ.push_back(arr[nx][ny]);
					x = nx;
					y = ny;
				}
			}
			nx += dx[dir];
			ny += dy[dir];
		}
		for (int j = DQ.size(); j < N; j++)
			DQ.push_back(0);


		int ax = i, ay = i;
		if (dir == 0 || dir == 1)
			ax = 0;
		else
			ay = 0;

		while (!DQ.empty()) {
			if (dir == 0 || dir == 2) {
				arr[ax][ay] = DQ.front();
				DQ.pop_front();
			}
			else {
				arr[ax][ay] = DQ.back();
				DQ.pop_back();
			}
			ax += dx[dir] * dx[dir];
			ay += dy[dir] * dy[dir];
		}
	}
}


void max_check() {
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			MAX = max(MAX, arr[x][y]);
}

void recur(int counting) {
	if (counting == 5) {
		max_check();
	}
	else {
		max_check();
		long long temp[20][20];
		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				temp[x][y] = arr[x][y];
		for (int i = 0; i < 4; i++) {
			move(i);
			recur(counting + 1);
			for (int x = 0; x < N; x++)
				for (int y = 0; y < N; y++)
					arr[x][y] = temp[x][y];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int x = 0; x < N; ++x)
		for (int y = 0; y < N; ++y)
			cin >> arr[x][y];
	recur(0);
	printf("%lld\n", MAX);
}