#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    int n, temp, cnt;
    bool flag;
    cin >> n;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        while (!s.empty() && s.top() < temp)
        {
            cnt++;
            s.pop();
        }
        if (!s.empty())
        {
            if (s.top() == temp)
            {
                cnt++;
                s.pop();
            }
            else
                cnt++;
        }
        s.push(temp);
    }
    while (!s.empty())
    {
        cnt++;
        s.pop();
    }

    cout << cnt;

    return 0;
}
