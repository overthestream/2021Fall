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

    for (int i = 0; i < n; i++)
    {
        int minN = 9999999999;
        for (int j = i - l + 1; j <= i; j++)
        {
            if (j < 0)
                continue;
            minN = min(minN, D[j]);
        }
        cout << minN << " ";
    }

    return 0;
}
