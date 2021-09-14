#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;

int i, T;

void input();
void output();

int main()
{
  scanf("%d", &T);
  for (i = 0; i < T; ++i)
  {
    input();
    output();
  }
}

void input()
{
  int tmp;
  scanf("%d", &tmp);
  if (i & 1)
    minHeap.push(tmp);
  else
    maxHeap.push(tmp);
  if (!i)
    return;
  while (minHeap.top() < maxHeap.top())
  {
    int smaller = minHeap.top();
    int bigger = maxHeap.top();

    minHeap.pop();
    maxHeap.pop();

    minHeap.push(bigger);
    maxHeap.push(smaller);
  }
}
void output()
{
  printf("%d\n", maxHeap.top());
}