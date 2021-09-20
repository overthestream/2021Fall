#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define POST 'P'
#define HOUSE 'K'

using namespace std;

int N;
char map[50][50];
int altitude[50][50];
pair<int, int> post;
vector<int> ordered;
int houses;

int di[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dj[] = {1, -1, 0, 1, -1, 1, -1, 0};

int lo, hi, ans;

void solve();
bool isValid(int, int);
bool BFS();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    {
      cin >> map[i][j];
      if (map[i][j] == POST)
        post = make_pair(i, j);
      else if (map[i][j] == HOUSE)
        ++houses;
    }

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    {
      cin >> altitude[i][j];
      ordered.push_back(altitude[i][j]);
    }

  sort(ordered.begin(), ordered.end());
  ordered.erase(unique(ordered.begin(), ordered.end()), ordered.end());

  ans = 10000000;

  solve();

  cout << ans;
}

void solve()
{
  while (lo < ordered.size() && hi < ordered.size())
    if (altitude[post.first][post.second] < ordered[lo] || altitude[post.first][post.second] > ordered[hi])
      hi++;
    else if (BFS())
      ans = min(ans, ordered[hi] - ordered[lo++]);
    else
      hi++;
}

bool isValid(int i, int j)
{
  return (i >= 0 && i < N && j >= 0 && j < N && altitude[i][j] >= ordered[lo] && altitude[i][j] <= ordered[hi]);
}

bool BFS()
{
  queue<pair<int, int> > q;
  bool visited[50][50] = {
      false,
  };

  if (isValid(post.first, post.second))
  {
    q.push(post);
    visited[post.first][post.second] = true;
  }
  int cnt = 0;
  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();
    for (int i = 0; i < 8; ++i)
    {
      int ni = cur.first + di[i];
      int nj = cur.second + dj[i];
      if (isValid(ni, nj) && !visited[ni][nj])
      {
        if (map[ni][nj] == HOUSE)
          cnt++;
        q.push(make_pair(ni, nj));
        visited[ni][nj] = true;
      }
    }
  }
  return cnt == houses;
}
