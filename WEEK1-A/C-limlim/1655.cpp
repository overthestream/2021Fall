
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define nummax 1000010
#define ll long long
#define pii pair<int, int>
using namespace std;

//vector<int> v;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
int curr, n;

// int main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0), cout.tie(0);
// 	cin >> n;
// 	while(n--) {
// 		cin >> x;
// 		v.push_back(x);
// 		int vsize = v.size();
// 		sort(v.begin(), v.end());
// 		if (vsize % 2 == 0) cout << v[vsize / 2 - 1] <<"\n";
// 		else cout << v[vsize / 2] << "\n";
// 	}
// }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	while(n--) {
		cin >> curr;

		if( maxq.size() == 0) maxq.push(curr);
		else {
			if(maxq.size() > minq.size()) minq.push(curr);
			else maxq.push(curr);

			if( maxq.top() > minq.top()) {
				int tmp = maxq.top(); maxq.pop();
				maxq.push(minq.top()); minq.pop();
				minq.push(tmp); 
			}
		}

		cout << maxq.top() << "\n";
	}
}