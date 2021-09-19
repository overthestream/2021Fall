#include <iostream>
#include <vector>

using namespace std;

int N, cnt;
vector<int> adj[500];
bool visited[500] = {1, 0};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  int M;
  cin >> M;

  for (int i = 0; i < M; ++i)
  {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  vector<int> list;

  for (int i = 0; i < adj[0].size(); ++i)
  {
    ++cnt;
    list.push_back(adj[0][i]);
    visited[adj[0][i]] = true;
  }

  for (int i = 0; i < list.size(); ++i)
  {
    int cur = list[i];
    for (int j = 0; j < adj[cur].size(); ++j)
    {
      int next = adj[cur][j];
      if (!visited[next])
      {
        ++cnt;
        visited[next] = true;
      }
    }
  }
  cout << cnt;
}
