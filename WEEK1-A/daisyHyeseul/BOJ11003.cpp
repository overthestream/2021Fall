#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    deque<pii> dec;
    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (dec.empty())
        {
            dec.push_front(make_pair(i, x));
        }
        else
        {
            if (dec.back().second <= x)
            {
                dec.push_back(make_pair(i, x));
            }
            else
            {
                while (dec.back().second > x && !dec.empty())
                {
                    dec.pop_back();
                }
                dec.push_back(make_pair(i, x));
            }
        }
        while (dec.front().first < i - L + 1 && !dec.empty())
        {
            dec.pop_front();
        }
        cout << dec.front().second << " ";
    }
}