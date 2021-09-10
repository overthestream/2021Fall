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
    cnt = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (!s.empty() && s.top() < temp)
        {
            cnt++;
            s.pop();
        }
        if (!s.empty() && s.top() == temp)
        {
            cnt++;
            s.pop();
        }
        s.push(temp);
    }

    cout << cnt;

    return 0;
}
