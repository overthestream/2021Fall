#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator()(int x, int y)
    {
        if (abs(x) > abs(y))
            return true;
        else if (abs(x) == abs(y))
            if (x > y)
                return true;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
        }
        else
            pq.push(temp);
    }

    return 0;
}
