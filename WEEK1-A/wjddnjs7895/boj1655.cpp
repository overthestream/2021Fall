#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main() {
	int N;
	priority_queue<int, vector<int>> PQ_front;
	priority_queue<int, vector<int>, greater<int>> PQ_back;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);
		if (!PQ_front.size())
			PQ_front.push(num);
		else if (PQ_front.size() > PQ_back.size()) {
			if (num > PQ_front.top())
				PQ_back.push(num);
			else {
				PQ_back.push(PQ_front.top());
				PQ_front.pop();
				PQ_front.push(num);
			}
		}
		else {
			if (num < PQ_back.top())
				PQ_front.push(num);
			else {
				PQ_back.push(num);
				PQ_front.push(PQ_back.top());
				PQ_back.pop();
			}
		}
		printf("%d\n", PQ_front.top());
	}
}