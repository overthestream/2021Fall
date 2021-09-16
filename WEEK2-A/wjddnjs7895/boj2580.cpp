#define _SRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[9][9], flag = 1;

void print_arr() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

bool check_xy(int x, int y)
{
	int xtemp[10] = { 0, };
	int ytemp[10] = { 0, };
	for (int i = 0; i < 9; i++)
	{
		xtemp[arr[i][y]] += 1;
		ytemp[arr[x][i]] += 1;
	}
	for (int i = 1; i < 10; i++)
	{
		if (xtemp[i] > 1)
			return false;
		if (ytemp[i] > 1)
			return false;
	}
	return true;
}

bool check_box(int x, int y) {
	int temp[10] = { 0, };
	int rx = x / 3 * 3;
	int ry = y / 3 * 3;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			temp[arr[rx + i][ry + j]] += 1;
	for (int i = 1; i <= 9; i++)
		if (temp[i] > 1)
			return false;
	return true;
}

void func(int x, int y) {
	if (x == 9) {
		print_arr();
		flag = 0;
	}
	if (flag) {
		if (!arr[x][y]) {
			for (int i = 1; i < 10; ++i) {
				arr[x][y] = i;
				if (check_xy(x, y) && check_box(x, y)) {
					if (y == 8)
						func(x + 1, 0);
					else
						func(x, y + 1);
				}
			}
			arr[x][y] = 0;
		}
		else {
			if (y == 8)
				func(x + 1, 0);
			else
				func(x, y + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> arr[i][j];
	func(0, 0);

}