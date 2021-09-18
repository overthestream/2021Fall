#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<int, int>> s;
    int n, temp;
    long long cnt, same;
    bool flag;
    cin >> n;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        same = 1;
        while (!s.empty() && s.top().first < temp)
        {
            cnt += s.top().second;
            s.pop();
        }
        if (!s.empty())
        {
            if (s.top().first == temp)
            {
                cnt += s.top().second;
                same = s.top().second + 1;
                if (s.size() > 1)
                    cnt++;
                s.pop();
            }
            else
                cnt++;
        }
        s.push({temp, same});
    }
    cout << cnt;

    return 0;
}
