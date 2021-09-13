// 두번 만지기는 만지지 않은 것과 같다.
// 즉, 모든 전구 칸은 만지거나 안만지거나 두가지 경우가 존재한다.
// 또한, 순서는 중요하지 않다.

// 그러므로 총 경우의 수는 2^(8*8) <= 좀 무리가 있는 수

// 그런데, 만약 [i][j]가 꺼져있다면, 인접한 전구나 본인을 켜야함 .
// 그렇다면 꺼진 수 * 9개의 칸을 봐야함. (중복 제외)
// 최대 시간은 2^30승? 정도가 마지노선일 것.

// 비슷한 형태로, 대각선을 제외하고 십자가 모양으로 전구가 반전되는 문제는
// 첫 줄은 완전 탐색을 하고, 이후 라인은 바로 윗 줄의 전구를 끄거나 키도록
// 나머지를 그리디하게 탐색하여 봄.
// https://geniusjo-story.tistory.com/412

// 이런 문제의 풀이가 가능한 이유.
// 루프는 한 행 한 행을 돈다.
// 그러면, 십자가 모양으로 킨다고 할 때, 나머지 위치는 다음 루프에 방문할 가능성이 생기지만,
// 바로 위쪽 전구는 이번 루프가 영향을 줄 수 있는 마지막 루프이다.
// 그러므로 위쪽 전구가 꺼져(켜져) 있다면 지금 루프에서 무조건 켜야하는 것.
// 이것을 기준으로 그리디하게 생각한 풀이이다.

// 대신 이 문제는 십자가 모양이 아니라 3x3 사각형 모양으로 영향을 준다.
// 그렇다면 1 2 3
//        4 5 6
//        7 8 9 를 위치로 할 때,
// 다음 루프에서는 방문 가능성이 있지만 이번 노드가 마지막인 전구는
// 1번 위치밖에 없다. 
// 루프는 오른쪽 아래를 향하므로.
// 그러므로 이번 루프에서 [i-1][j-1]번 전구가 꺼져있다면,
// [i][j]의 전구를 만져야 하고.
// 그렇다면 첫번째 완전탐색은 첫 행이 아니라, 첫 행+첫 열 모두를 
// 완전탐색하고 이 방식으로 아래 쪽을 탐색하면 풀린다.

#include <cstdio>
#include <iostream>
#define MAX 987654321

using namespace std;

bool temp[8][8], org[8][8];
int n, m;
int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dx[] = {1, -1, 0, 1, -1, 0, 1, -1, 0};
int cnt, result = MAX;

void turn(int, int);
bool isDone();
bool isValid(int, int);
void solve();
void init();

int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      char tmp;
      scanf(" %c", &tmp);
      org[i][j] = tmp == '*';
    }
  solve();
}

void solve()
{
  for (int i = 0; i < 1 << n; ++i)
  {
    for (int j = 0; j < 1 << m; ++j)
    {
      init();
      for (int y = 0; y < n; ++y)
        if (i & 1 << y)
          turn(y, 0);
      for (int x = 0; x < m; ++x)
        if (j & 1 << x)
          turn(0, x);
      for (int y = 1; y < n; ++y)
      {
        for (int x = 1; x < m; ++x)
        {
          if (!temp[y - 1][x - 1])
            turn(y, x);
        }
      }
      if (isDone())
        result = min(result, cnt);
    }
  }
  printf("%d", result == MAX ? -1 : result);
}

bool isValid(int y, int x)
{
  if (y >= 0 && y < n)
    if (x >= 0 && x < m)
      return true;
  return false;
}

bool isDone()
{
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!temp[i][j])
        return false;
  return true;
}

void turn(int y, int x)
{
  ++cnt;
  for (int i = 0; i < 9; ++i)
  {
    int ydy = y + dy[i];
    int xdx = x + dx[i];
    if (isValid(ydy, xdx))
      temp[ydy][xdx] = !temp[ydy][xdx];
  }
}

void init()
{
  cnt = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      temp[i][j] = org[i][j];
}