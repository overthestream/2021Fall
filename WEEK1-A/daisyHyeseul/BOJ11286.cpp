#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        if (abs(a) > abs(b))
            return true;
        else if (abs(a) == abs(b))
        {
            if (a > b)
                return true;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int, vector<int>, compare> pq;
    int N = 0;
    int x = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x)
        {
            pq.push(x);
        }
        else
        {
            if (!pq.empty())
            {

                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << 0 << "\n";
        }
    }
}
// int minheap[100001] = {0};
// int heapcount = 0;

// bool operate(int a, int b)
// {
//     if (abs(a) > abs(b))
//         return true;
//     else if (abs(a) == abs(b))
//     {
//         if (a > b)
//             return true;
//     }
//     return false;
// }

// void pushHeap(int a)
// {
//     minheap[++heapcount] = a;
//     int child = heapcount;
//     int parent = heapcount / 2;

//     while (child > 1 && operate(minheap[parent], minheap[child]))
//     {
//         int tmp = minheap[parent];
//         minheap[parent] = minheap[child];
//         minheap[child] = tmp;
//         child = parent;
//         parent = child / 2;
//     }
// }

// int popHeap()
// {
//     int result = minheap[1];
//     minheap[1] = minheap[heapcount];
//     heapcount--;
//     int parent = 1;
//     int child = parent * 2;
//     if (parent * 2 + 1 <= heapcount)
//         child = operate(minheap[child], minheap[parent * 2 + 1]) ? parent * 2 + 1 : child;

//     while (child <= heapcount && operate(minheap[parent], minheap[child]))
//     {
//         int tmp = minheap[parent];
//         minheap[parent] = minheap[child];
//         minheap[child] =tmp;
//         parent = child;
//         child = child * 2;
//         if (child * 2 + 1 <= heapcount)
//             child = operate(minheap[child], minheap[parent * 2 + 1]) ? parent * 2 + 1 : child;
//     }
//     return result;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int N = 0;
//     int x = 0;
//     cin >> N;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> x;
//         if (x)
//         {
//             pushHeap(x);
//         }
//         else
//         {
//             if (heapcount)
//                 cout << popHeap() << "\n";
//             else
//                 cout << 0 << "\n";
//         }
//     }
// }