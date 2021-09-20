#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int N, M;
int map[1000][1000];
int visit[1000][1000][2];

int BFS();

int main(void)
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    string temp;
    cin >> temp;

    for (int j = 0; j < M; j++)
      map[i][j] = temp[j] - '0';
  }

  cout << BFS();
}

int BFS()
{
  queue<pair<pair<int, int>, int> > q;
  q.push(make_pair(make_pair(0, 0), 1));
  visit[0][0][1] = 1;

  while (!q.empty())
  {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int chance = q.front().second;
    q.pop();

    if (y == N - 1 && x == M - 1)
      return visit[y][x][chance]; //시작하는 칸도 포함

    for (int i = 0; i < 4; i++)
    {
      int nextY = y + dy[i];
      int nextX = x + dx[i];

      if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
      {
        if (map[nextY][nextX] == 1 && chance)
        {
          visit[nextY][nextX][chance - 1] = visit[y][x][chance] + 1;
          q.push(make_pair(make_pair(nextY, nextX), chance - 1));
        }
        else if (map[nextY][nextX] == 0 && visit[nextY][nextX][chance] == 0)
        {
          visit[nextY][nextX][chance] = visit[y][x][chance] + 1;
          q.push(make_pair(make_pair(nextY, nextX), chance));
        }
      }
    }
  }
  return -1;
}
