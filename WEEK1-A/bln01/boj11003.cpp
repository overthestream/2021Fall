#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > pq;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, L;
  cin >> N >> L;

  for (int i = 1; i <= N; ++i)
  {
    int temp;
    cin >> temp;

    pq.push(make_pair(temp, i));

    int lowerbound = max(0, i - L + 1);
    while (1)
    {
      pii top = pq.top();
      if (top.second >= lowerbound && top.second <= i)
      {
        cout << top.first << " ";
        break;
      }
      pq.pop();
    }
  }
}