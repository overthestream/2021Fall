#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result;
    bool flag;
    string str;
    cin >> n;

    result = 0;
    for (int cnt = 0; cnt <= n; ++result)
    {
        flag = true;
        str = to_string(result);
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i - 1] - str[i] <= 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ++cnt;
    }

    cout << result;

    return 0;
}
