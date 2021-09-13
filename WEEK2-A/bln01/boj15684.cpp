// 틀렸던 이유: 사다리 중복을 피하려고 
// 이전까지 탐색한 인덱스가 i,j 였으면, 그 이후부터 탐색을 했으나.(도식화 시 오른쪽 아래 있는 놈들만)
// 그러면 row값은 작지만 col은 크거나, 그 반대인 값을 제대로 탐색하지 못했음.

#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int ladder[12][32]; // [i][j] : i~i+1, jth height
int N, M, H;
pii added[3];
bool isFound;

void check(int);
void solve();
void whatToAdd(int, int);

int main()
{
  scanf("%d %d %d", &N, &M, &H);
  for (int i = 0; i < M; ++i)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    ladder[b - 1][a - 1] = 1;
  }
  solve();

  if (!isFound)
    printf("-1");
}

void check(int addNum)
{
  for (int i = 0; i < addNum; ++i)
  {
    int col = added[i].first;
    int row = added[i].second;

    ladder[col][row] = 1;
  }

  for (int i = 0; i < N; ++i)
  {
    int cur = i;
    for (int j = 0; j < H; ++j)
    {
      if (ladder[cur][j])
      {
        cur = cur + 1;
      }
      else if (cur > 0 && ladder[cur - 1][j])
      {
        cur = cur - 1;
      }
    }
    if (cur != i)
      break;
    if (i == N - 1)
    {
      printf("%d", addNum);
      isFound = true;
    }
  }

  for (int i = 0; i < addNum; ++i)
  {
    int col = added[i].first;
    int row = added[i].second;

    ladder[col][row] = 0;
  }
}
void solve()
{

  for (int i = 0; i < 4; ++i)
  {
    whatToAdd(0, i);
    if (isFound)
      break;
  }
}

void whatToAdd(int addedNum, int addNum)
{
  if (addedNum == addNum)
  {
    check(addNum);
    return;
  }
  int col, row;
  if (!addedNum)
  {
    col = 0;
    row = 0;
  }
  else
  {
    col = added[addedNum - 1].first;
    row = added[addedNum - 1].second;
  }
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < N - 1; ++j)
    {
      if (i < row || (i == row && j < col))
        continue;
      if (!ladder[j][i])
      {
        added[addedNum].first = j;
        added[addedNum].second = i;
        whatToAdd(addedNum + 1, addNum);
        if (isFound)
          return;
      }
    }
}