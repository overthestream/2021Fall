#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<int> mlist[501];
bool check[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(check, false, sizeof(check));
    int n, m, temp1, temp2;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        mlist[temp1].push_back(temp2);
        mlist[temp2].push_back(temp1);
    }

    for (int pos = 0; pos < mlist[1].size(); pos++)
    { // 상근이의 친구
        temp1 = mlist[1][pos];
        check[temp1] = true;
        for (int i = 0; i < mlist[temp1].size(); i++) //상근이의 친구의 친구
        {
            check[mlist[temp1][i]] = true;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (check[i])
            ++cnt;
    }

    cout << cnt;

    return 0;
}