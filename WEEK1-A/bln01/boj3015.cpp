#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  stack<pll> descend;
  ll result = 0;

  for (int i = 0; i < N; ++i)
  {
    ll temp;
    cin >> temp;

    int ov = 1;
    while (!descend.empty() && descend.top().first <= temp)
    {
      if (descend.top().first == temp)
      {
        result += descend.top().second;
        ov = descend.top().second + 1;
        descend.pop();
      }
      else
      {
        result += descend.top().second;
        descend.pop();
        ov = 1;
      }
    }
    if (!descend.empty())
      ++result;
    descend.push(make_pair(temp, ov));
  }
  cout << result;
}
