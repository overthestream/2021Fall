#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //pq1은 내림차순으로 저장하고, pq2는 오름차순으로 저장한다.
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (pq1.size() == pq2.size())
            pq1.push(temp);
        else
            pq2.push(temp);

        if (!pq1.empty() && !pq2.empty() && pq1.top() > pq2.top())
        {
            temp = pq1.top();
            pq1.pop();
            pq1.push(pq2.top());
            pq2.pop();
            pq2.push(temp);
        }

        cout << pq1.top() << " ";
    }

    return 0;
}
