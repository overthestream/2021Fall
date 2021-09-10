#include <bits/stdc++.h>

using namespace std;

int main() 
{
    //입출력 속도 업
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);

	int N;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    
	cin >> N;

	for (int i = 0; i < N; i++) 
    {
		int num;
		cin >> num;

		if (num == 0) 
        {
			if (pq.empty()) 
            {
				cout << "0" << "\n";
			}
			else 
            {
				cout << pq.top().first * pq.top().second << "\n";
				pq.pop();
			}
		}
		else
        {
			if (num < 0) 
            {
				num *= -1;
				pq.push(make_pair(num, -1));
			}
			else 
				pq.push(make_pair(num, 1));
		}
	}
}