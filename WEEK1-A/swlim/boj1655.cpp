#include <bits/stdc++.h>

using namespace std;

int main() 
{
    //입출력 속도 업
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);

	int N;
	priority_queue<int, vector<int>, less<>> pq_Max;
    priority_queue<int, vector<int>, greater<>> pq_Min;
    
	cin >> N;

	for (int i = 0; i < N; i++) 
    {
		int temp;
		cin >> temp;

        if (pq_Max.size() - pq_Min.size() == 0)
            pq_Max.push(temp);
        else
            pq_Min.push(temp);

        if (!pq_Max.empty() && !pq_Min.empty())
        {
            if (pq_Max.top() > pq_Min.top()) 
            {
                pq_Max.push(pq_Min.top());
                pq_Min.pop();
                pq_Min.push(pq_Max.top());
                pq_Max.pop();
            }
        }
        cout << pq_Max.top() << '\n';
	}
    return 0;
}