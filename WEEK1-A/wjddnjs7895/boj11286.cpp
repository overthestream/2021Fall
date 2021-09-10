#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main() {
	int N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);
		if (num)
			PQ.push(make_pair(abs(num), num));
		else {
			if (PQ.empty())
				printf("0\n");
			else {
				printf("%d\n", PQ.top().second);
				PQ.pop();
			}
		}
	}
}