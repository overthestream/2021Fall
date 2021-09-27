#include <iostream>
#include <cmath>

using namespace std;

char star[7700][7700];

void print(int, int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n * 2 - 1; ++i)
    for (int j = 0; j < n * 2 - 1; ++j)
      star[i][j] = ' ';

  print(0, 0, n);

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n - 1 - i; ++j)
      cout << ' ';
    for (int j = 0; j < n * 2 - 1 - (n - 1 - i); ++j)
      cout << star[i][j];
    cout << '\n';
  }
}

void print(int r, int c, int size)
{
  if (size == 3)
  {
    for (int i = r; i < r + 3; ++i)
      for (int j = c; j < c + (i - r + 1) * 2 - 1; ++j)
        if (i == r + 1 && j == c + 1)
          star[i][j] = ' ';
        else
          star[i][j] = '*';
    return;
  }
  else
  {
    print(r, c, size / 2);
    print(r + size / 2, c, size / 2);
    print(r + size / 2, c + size, size / 2);
  }
}