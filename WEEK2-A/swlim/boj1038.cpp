#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
vector<ll> Vec;

void make(ll n, int k)
{
	Vec.push_back(n);

	for(int i = k - 1; i >= 0; i--)
        make(n * 10 + i, i);
}

int main()
{
    // 입력 속도 업
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    for(int i = 0; i < 10; i++)
        make(i, i);
        
	sort(Vec.begin(), Vec.end());
	
	int N;
    cin >> N;

    ll result = Vec.size() > N ? Vec[N] : -1;

    cout << result << endl;
	return 0;
}