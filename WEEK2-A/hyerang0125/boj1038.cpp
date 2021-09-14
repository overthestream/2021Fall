#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
long long nlist[MAX + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, idx;
    long long result;
    queue<long long> q;
    cin >> n;

    idx = 0;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
        nlist[idx++] = i;
    }

    while (idx <= n)
    {
        if (q.empty())
            break;

        long long temp = q.front();
        q.pop();
        for (int i = 0; i < temp % 10; i++)
        {
            q.push(temp * 10 + i);
            nlist[idx++] = temp * 10 + i;
        }
    }

    if (nlist[n] == 0 && n != 0)
        cout << "-1";
    else
        cout << nlist[n];

    return 0;
}
