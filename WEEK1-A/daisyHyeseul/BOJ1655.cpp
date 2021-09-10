#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    int N, x;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (!maxheap.size())
        {
            maxheap.push(x);
        }
        else
        {

            if (maxheap.size() > minheap.size())
                minheap.push(x);
            else if (maxheap.size() == minheap.size())
                maxheap.push(x);
            if (maxheap.top() > minheap.top())
            {
                maxheap.push(minheap.top());
                minheap.push(maxheap.top());
                maxheap.pop();
                minheap.pop();
            }
        }

        cout << maxheap.top() << "\n";
    }
}