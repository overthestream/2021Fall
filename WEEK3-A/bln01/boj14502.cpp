#include <iostream>
#include <queue>

using namespace std;

int org[8][8];
int tmp[8][8];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int rows, cols;

void solve();
bool makeCase(int, int, int);
void simulate();
void count(int *);
bool isValid(int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> rows >> cols;

  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      cin >> org[i][j];

  solve();
}

void solve()
{
  int maxCnt = 0;
  for (int i = 0; i < rows * cols; ++i)
    for (int j = i + 1; j < rows * cols; ++j)
      for (int k = j + 1; k < rows * cols; ++k)
      {
        if (makeCase(i, j, k))
        {
          simulate();
          count(&maxCnt);
        }
      }
  cout << maxCnt;
}

bool makeCase(int i, int j, int k)
{
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      tmp[i][j] = org[i][j];
  int walls[] = {i, j, k};
  for (int idx = 0; idx < 3; ++idx)
  {
    int row = walls[idx] / cols;
    int col = walls[idx] % cols;
    if (org[row][col])
      return false;
    tmp[row][col] = 1;
  }
  return true;
}

void simulate()
{
  queue<pair<int, int> > idx;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      if (tmp[i][j] == 2)
        idx.push(make_pair(i, j));

  while (!idx.empty())
  {
    pair<int, int> cur = idx.front();
    idx.pop();
    for (int i = 0; i < 4; ++i)
    {
      int nextI = cur.first + dx[i], nextJ = cur.second + dy[i];
      if (isValid(nextI, nextJ) && !tmp[nextI][nextJ])
      {
        tmp[nextI][nextJ] = 2;
        idx.push(make_pair(nextI, nextJ));
      }
    }
  }
}

void count(int *curMax)
{
  int cnt = 0;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      if (!tmp[i][j])
        ++cnt;
  *curMax = max(*curMax, cnt);
}

bool isValid(int i, int j)
{
  return (i < 0 || i >= rows || j < 0 || j >= cols) ? false : true;
}