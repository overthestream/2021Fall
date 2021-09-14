#define _SRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int arr[12][32];
int col, row, N, result = 0;

bool check() {
	for (int n = 1; n <= col; ++n) {
		int num = n;
		int idx = 1;
		while (idx <= row) {
			int flag = 1;
			for (int i = idx; i <= row; ++i) {
				if (arr[num][i]) {
					num += arr[num][i];
					idx = i + 1;
					flag = 0;
					break;
				}
			}
			if (flag) break;
		}
		if (num != n)
			return false;
	}
	return true;
}

void recur(int num, int counting) {
	for (int b = 1; b <= col - 1; ++b) {
		for (int a = 1; a <= row; ++a) {
			if (result) break;
			if (!arr[b][a] && arr[b - 1][a] != 1 && !arr[b + 1][a]) {
				arr[b][a] = 1;
				arr[b + 1][a] = -1;
				if (counting + 1 == num) {
					if (check())
						result = 1;
				}
				else {
					recur(num, counting + 1);
				}
				arr[b][a] = 0;
				arr[b + 1][a] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> col >> N >> row;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		arr[b][a] = 1;
		arr[b + 1][a] = -1;
	}
	if (check())
		printf("0\n");
	else {
		for (int i = 1; i <= 3; ++i) {
			recur(i, 0);
			if (result) {
				printf("%d\n", i);
				break;
			}
			if (i == 3)
				printf("-1\n");
		}
	}
}