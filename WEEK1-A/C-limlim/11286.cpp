
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define pii pair<int, int>
using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		if( abs(a) == abs(b)) {
			return a > b;
		} else return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, cmp> q;
int n, x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	while(n--) {
		cin >> x;
		if( x != 0 ) {
			q.push(x);
			continue;
		} 

		if(q.size() == 0) cout << "0\n";
		else {
			x = q.top(); q.pop();
			cout << x << "\n";
		}
	}
}