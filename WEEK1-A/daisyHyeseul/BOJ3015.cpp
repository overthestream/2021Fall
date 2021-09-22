#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    long long result = 0;
    stack<pair<long long, long long>> s; //키, 중복된 개수
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long h;
        cin >> h;

        int count = 1;
        while (!s.empty())
        {
            if (s.top().first < h)
            {
                result += s.top().second;
                count = 1;
                s.pop();
            }
            else if (s.top().first == h)
            {
                result += s.top().second;
                count = s.top().second + 1;
                s.pop();
            }
            else
            {
                result++;
                break;
            }
        }
        s.push(make_pair(h, count));
    }

    cout << result;

    return 0;
}