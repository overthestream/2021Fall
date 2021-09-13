#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    deque<pair<int,int>> deq;

    for (int i = 0; i < N; i++)
    {
        // 입력 속도 업
	    ios::sync_with_stdio(false);
        cin.tie(NULL);
	    cout.tie(NULL);

        int A;
        cin >> A;

        if (!deq.empty() && deq.front().second < i - L + 1) 
        {
            deq.pop_front();
        }

        while (!deq.empty() && deq.back().first > A) 
        {
            deq.pop_back();
        }

        deq.push_back({A, i});
        cout << deq.front().first << " ";
    }

    return 0;
}