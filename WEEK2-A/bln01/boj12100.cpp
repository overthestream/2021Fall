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
