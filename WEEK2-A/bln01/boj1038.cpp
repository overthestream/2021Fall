#include <iostream>

using namespace std;

int N, cnt;
bool isFound = false;
char num[10];
void DLS(int, int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i < 11; ++i)
    for (int j = 0; j < 10; ++j)
    {

      if (isFound)
        break;
      DLS(i, 1, j);
    }
  if (!isFound)
    printf("%d", -1);
}
void DLS(int lengthLimit, int curLength, int curNum)
{
  if (isFound)
    return;
  num[curLength - 1] = '0' + curNum;
  if (lengthLimit == curLength)
  {
    ++cnt;

    if (N + 1 == cnt)
    {
      for (int i = 0; i <= lengthLimit - 1; ++i)
        printf("%c", num[i]);
      isFound = true;
    }
    return;
  }

  for (int i = 0; i < 10; ++i)
  {
    if (i >= curNum)
      continue;
    DLS(lengthLimit, curLength + 1, i);
    num[curLength - 1] = '0' + curNum;
  }
}