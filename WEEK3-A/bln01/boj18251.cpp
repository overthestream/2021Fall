#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
typedef long long ll;

int val[262144];
int y[262144];
int nodeInX[262144];

int xVal;

int N;

void setCoordinate(int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i = 1; i <= N; ++i)
    cin >> val[i];
  setCoordinate(1, 0);

  ll result = LLONG_MIN;
  for (int i = 0; i <= y[N]; ++i)
  {
    for (int j = i; j <= y[N]; ++j)
    {
      vector<int> weights;
      for (int k = 0; k < N; ++k)
      {
        int index = nodeInX[k];
        if (y[index] >= i && y[index] <= j)
          weights.push_back(val[index]);
      }
      ll dp = weights[0];
      result = max(result, dp);
      for (int k = 1; k < weights.size(); ++k)
      {
        dp = max(ll(0), dp) + weights[k];
        result = max(result, dp);
      }
    }
  }
  cout << result;
}

void setCoordinate(int index, int depth)
{
  if (index > N)
    return;
  setCoordinate(index * 2, depth + 1);
  nodeInX[xVal++] = index;
  y[index] = depth;
  setCoordinate(index * 2 + 1, depth + 1);
}