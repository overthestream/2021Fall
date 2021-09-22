// 오답이 자꾸 나왔던 이유:
// 2048 시뮬레이션 구현 시 합쳐지는 로직의 문제
// 처음에 구현 방식: array를 돌면서 연속으로 같은 놈이 있으면
// *2를 해서 큐에 넣어놨다가 배열을 다시 씀
// 문제점: 4 0 4 와 같은 경우를 인식하지 못함

// 다음 방식: 수가 나올 때마다 큐에 넣어 놨다가,
// 배열을 다시 쓰면서 큐에서 두 개씩 빼서 같으면 *2를 해줌
// 문제점: 2 4 4 RIGHT 와 같은 경우를 인식하지 못함.

// 해결: 큐를 두 개 써서 
// 큐에서 하나를 일단 빼고, 그게 front의 값과 같으면,
// pop을 한번 더 해 준 뒤 *2를 해서 새 큐에 넣어줌 
// 만약 같지 않으면, 그냥 새 큐에 넣고 다음 Loop로 감.
// 위의 모든 반례를 해결 가능

#include <queue>
#include <cstdio>
using namespace std;
int biggest, blockSize;
enum direction
{
  LEFT,
  RIGHT,
  UP,
  DOWN
};
void move(int dir, int next[][20]);
void simulate(int moved, int cur[][20]);

int main()
{
  scanf("%d", &blockSize);
  int game[20][20] = {
      0,
  };
  for (int i = 0; i < blockSize; ++i)
    for (int j = 0; j < blockSize; ++j)
      scanf("%d", &game[i][j]);
  simulate(0, game);
  printf("%d", biggest);
}

void move(int dir, int next[][20])
{

  if (dir == LEFT)
  {
    for (int i = 0; i < 20; ++i)
    {
      queue<int> tmp;
      queue<int> newLine;
      for (int j = 0; j < 20; ++j)
      {
        if (next[i][j])
          tmp.push(next[i][j]);
      }
      while (!tmp.empty())
      {
        int first, second;
        first = tmp.front();
        tmp.pop();
        if (!tmp.empty())
        {
          if (first == tmp.front())
          {
            newLine.push(first * 2);
            tmp.pop();
          }
          else
          {
            newLine.push(first);
          }
        }
        else
        {
          newLine.push(first);
        }
      }
      for (int j = 0; j < 20; ++j)
      {
        if (newLine.empty())
        {
          next[i][j] = 0;
        }
        else
        {
          next[i][j] = newLine.front();
          newLine.pop();
        }
      }
    }
  }
  else if (dir == RIGHT)
  {
    for (int i = 0; i < 20; ++i)
    {
      queue<int> newLine;
      queue<int> tmp;
      for (int j = 19; j >= 0; --j)
      {
        if (next[i][j])
        {
          tmp.push(next[i][j]);
        }
      }
      while (!tmp.empty())
      {
        int first, second;
        first = tmp.front();
        tmp.pop();
        if (!tmp.empty())
        {
          if (first == tmp.front())
          {
            newLine.push(first * 2);
            tmp.pop();
          }
          else
          {
            newLine.push(first);
          }
        }
        else
        {
          newLine.push(first);
        }
      }
      for (int j = 19; j >= 0; --j)
      {
        if (newLine.empty())
        {
          next[i][j] = 0;
        }
        else
        {
          next[i][j] = newLine.front();
          newLine.pop();
        }
      }
    }
  }
  else if (dir == DOWN)
  {
    for (int j = 0; j < 20; ++j)
    {
      queue<int> newLine;
      queue<int> tmp;
      for (int i = 19; i >= 0; --i)
      {
        if (next[i][j])
        {
          tmp.push(next[i][j]);
        }
      }
      while (!tmp.empty())
      {
        int first, second;
        first = tmp.front();
        tmp.pop();
        if (!tmp.empty())
        {
          if (first == tmp.front())
          {
            newLine.push(first * 2);
            tmp.pop();
          }
          else
          {
            newLine.push(first);
          }
        }
        else
        {
          newLine.push(first);
        }
      }
      for (int i = 19; i >= 0; --i)
      {
        if (newLine.empty())
        {
          next[i][j] = 0;
        }
        else
        {
          next[i][j] = newLine.front();
          newLine.pop();
        }
      }
    }
  }
  else if (dir == UP)
  {
    for (int j = 0; j < 20; ++j)
    {
      queue<int> newLine;
      queue<int> tmp;
      for (int i = 0; i < 20; ++i)
      {
        if (next[i][j])
        {
          tmp.push(next[i][j]);
        }
      }
      while (!tmp.empty())
      {
        int first, second;
        first = tmp.front();
        tmp.pop();
        if (!tmp.empty())
        {
          if (first == tmp.front())
          {
            newLine.push(first * 2);
            tmp.pop();
          }
          else
          {
            newLine.push(first);
          }
        }
        else
        {
          newLine.push(first);
        }
      }
      for (int i = 0; i < 20; ++i)
      {
        if (newLine.empty())
        {
          next[i][j] = 0;
        }
        else
        {
          next[i][j] = newLine.front();
          newLine.pop();
        }
      }
    }
  }
};

void simulate(int moved, int cur[][20])
{
  if (moved == 5)
  {
    for (int i = 0; i < 20; ++i)
    {
      for (int j = 0; j < 20; ++j)
      {
        if (cur[i][j] > biggest)
          biggest = cur[i][j];
      }
    }
    return;
  }

  int original[20][20] = {
      0,
  };
  for (int j = 0; j < 20; ++j)
    for (int k = 0; k < 20; ++k)
      original[j][k] = cur[j][k];

  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 20; ++j)
      for (int k = 0; k < 20; ++k)
        cur[j][k] = original[j][k];
    move(i, cur);
    simulate(moved + 1, cur);
  }
};
