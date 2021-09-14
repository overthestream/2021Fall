#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i;
    long long result;
    queue<long long> q;
    cin >> n;

    for (int i = 0; i < 10; i++)
    {
        q.push(i);
        nlist.push_back(i);
    }

    while (nlist.size() <= n)
    {
        if (q.empty())
            break;

        long long temp = q.front();
        q.pop();
        for (int i = 0; i < temp % 10; i++)
        {
            q.push(temp * 10 + i);
            nlist.push_back(temp * 10 + i);
        }
    }

    if (nlist[n] == 0 && n != 0)
        cout << "-1";
    else
        cout << nlist[n];

    return 0;
}
