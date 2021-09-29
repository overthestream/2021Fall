#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

typedef struct
{
  int left;
  int right;
  int top;
  int bottom;

  int getSize()
  {
    return (right - left) * (top - bottom);
  }
} square;

int n;
pii arr[100];

square getBiggestSquare(int, int);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i].first >> arr[i].second;
  sort(arr, arr + n);

  cout << getBiggestSquare(0, n - 1).getSize();
}

bool isValid(pii left, square cur)
{
  if (left.first + 10 < cur.left)
    return false;
  if ((left.second >= cur.top || left.second < cur.bottom) && (left.second + 10 >= cur.top || left.second + 10 < cur.bottom))
    return false;

  return true;
}
bool isValid(square cur, pii right)
{
  if (right.first > cur.left)
    return false;
  if ((right.second >= cur.top || right.second < cur.bottom) && (right.second + 10 >= cur.top || right.second + 10 < cur.bottom))
    return false;

  return true;
}
square merge(int mid, int lo, int hi)
{
  square maximum, cur;
  maximum.left = arr[mid].first;
  maximum.bottom = arr[mid].second;
  maximum.top = maximum.bottom + 10;
  maximum.right = maximum.left + 10;
  cur.left = arr[mid].first;
  cur.bottom = arr[mid].second;
  cur.top = maximum.bottom + 10;
  cur.right = maximum.left + 10;

  int l = mid - 1, r = mid + 1;

  bool leftDone = l >= lo, rightDone = r <= hi;
  while (1)
  {
    square left, right;
    if (leftDone && rightDone)
      break;
    if (l >= lo && isValid(arr[l], cur))
    {
      left.left = arr[l].first;
      left.bottom = max(cur.bottom, arr[l].second);
      left.top = min(cur.top, arr[l].second + 10);
    }
    else
      leftDone = true;

    if (r <= hi && isValid(cur, arr[r]))
    {
      right.right = arr[r].first + 10;
      right.bottom = max(cur.bottom, arr[r].second);
      right.top = min(cur.top, arr[r].second + 10);
    }
    else
      rightDone = true;

    if (!leftDone && !rightDone)
    {
      if (left.getSize() >= right.getSize())
      {
        cur.left = arr[l].first;
        cur.bottom = max(cur.bottom, arr[l].second);
        cur.top = min(cur.top, arr[l].second + 10);
        l--;
      }
      else
      {
        cur.right = arr[r].first + 10;
        cur.bottom = max(cur.bottom, arr[r].second);
        cur.top = min(cur.top, arr[r].second + 10);
        r++;
      }
    }
    else if (!rightDone)
    {
      cur.right = arr[r].first + 10;
      cur.bottom = max(cur.bottom, arr[r].second);
      cur.top = min(cur.top, arr[r].second + 10);
      r++;
    }
    else if (!leftDone)
    {
      cur.right = arr[r].first + 10;
      cur.bottom = max(cur.bottom, arr[r].second);
      cur.top = min(cur.top, arr[r].second + 10);
      r++;
    }
    if (cur.getSize() > maximum.getSize())
    {
      maximum.left = cur.left;
      maximum.right = cur.right;
      maximum.top = cur.top;
      maximum.bottom = cur.bottom;
    }
  }

  return maximum;
}

square getBiggestSquare(int from, int to)
{
  if (from == to)
  {
    square base;
    base.left = arr[from].first;
    base.right = base.left + 10;
    base.bottom = arr[from].second;
    base.top = base.bottom + 10;
    return base;
  }

  int mid = (from + to) / 2;

  square left = getBiggestSquare(from, mid);
  square right = getBiggestSquare(mid + 1, to);
  square merged = merge(mid, from, to);

  if (left.getSize() >= right.getSize() && left.getSize() >= merged.getSize())
    return left;
  else if (merged.getSize() >= right.getSize() && merged.getSize() >= left.getSize())
    return merged;
  else
    return right;
}