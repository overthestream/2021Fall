#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;

ll N, counting = 0;
stack<pair<int, int>> S;

void recur(pair<int, int> num_pair) {
	int num = num_pair.first;
	if (S.empty())
		S.push(num_pair);
	else if (S.top().first == num) {
		int temp = S.top().second;
		counting += S.top().second;
		S.pop();
		recur(make_pair(num, temp + 1));
	}
	else if (S.top().first > num) {
		counting += 1;
		S.push(num_pair);
	}
	else {
		counting += S.top().second;
		S.pop();
		recur(num_pair);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		ll num;
		scanf("%lld", &num);
		recur(make_pair(num, 1));
	}
	printf("%lld\n", counting);
}