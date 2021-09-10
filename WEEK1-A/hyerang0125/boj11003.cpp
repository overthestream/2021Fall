#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    int *D = new int[n];
    for (int i = 0; i < n; i++)
        cin >> D[i];

    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++)
    {
        // 최대 L개의 값을 저장
        if (!dq.empty() && dq.front().second < i - l + 1)
            dq.pop_front();
        // 오름차순으로 저장하기 위해서 D[i]가 덱 내에서 제일 큰 숫자가 되도록 함
        while (!dq.empty() && dq.back().first > D[i])
            dq.pop_back();

        dq.push_back({D[i], i});
        cout << dq.front().first << " ";
    }

    return 0;
}
