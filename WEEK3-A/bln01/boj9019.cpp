#include <iostream>
#include <queue>
#include <string>

using namespace std;

char inst[] = {'D', 'S', 'L', 'R'};

int compute(int, int);
int computeBack(int, int);
void solve(int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i)
  {
    int src, dst;
    cin >> src >> dst;
    solve(src, dst);
  }
}

int compute(int src, int index)
{
  if (index == 0)
    return (2 * src) % 10000;
  else if (index == 1)
    return src ? src - 1 : 9999;
  else if (index == 2)
  {
    int tmp = src / 1000;
    return (src % 1000) * 10 + tmp;
  }
  else
  {
    int tmp = src % 10;
    return (src / 10) + tmp * 1000;
  }
}

void solve(int src, int dst)
{
  queue<pair<int, string> > BFS;
  bool visited[11010] = {
      0,
  };
  visited[src] = 1;
  BFS.push(make_pair(src, ""));

  while (!BFS.empty())
  {
    pair<int, string> cur = BFS.front();
    BFS.pop();
    for (int i = 0; i < 4; ++i)
    {
      int result = compute(cur.first, i);
      if (result < 0 || result >= 10000 || visited[result])
        continue;
      visited[result] = 1;
      if (result == dst)
      {
        cout << cur.second + inst[i] + '\n';
        return;
      }
      BFS.push(make_pair(result, cur.second + inst[i]));
    }
  }
}