#include <cstdio>
#include <cmath>

#define ROOT 1
int heap[100010];
int target = ROOT;

void input();
void push(int);
void pop();
void afterPush(int);
void afterPop();
int isHeapCorrect(int, int);

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
    input();
}

void input()
{
  int temp;
  scanf("%d", &temp);
  if (temp != 0)
    push(temp);
  else
    pop();
}

void push(int data)
{
  heap[target] = data;
  afterPush(target);
  target++;
}

void pop()
{
  if (target == ROOT)
    printf("0\n");
  else
  {
    printf("%d\n", heap[ROOT]);
    target--;
    heap[ROOT] = heap[target];
    afterPop();
  }
}

void afterPush(int target)
{
  int cur = target;
  int curParent;

  while (cur > ROOT)
  {
    curParent = cur / 2;
    if (isHeapCorrect(curParent, cur))
      break;
    int tmp = heap[curParent];
    heap[curParent] = heap[cur];
    heap[cur] = tmp;

    cur /= 2;
  }
}

void afterPop()
{
  int cur = ROOT;
  int leftChild, rightChild, priorChild;

  while (cur < target)
  {
    leftChild = cur * 2;
    rightChild = cur * 2 + 1;

    if (leftChild >= target)
      break;
    if (abs(heap[leftChild]) < abs(heap[rightChild]) || rightChild >= target)
      priorChild = leftChild;
    else if (abs(heap[leftChild]) == abs(heap[rightChild]) && heap[leftChild] < heap[rightChild])
      priorChild = leftChild;
    else
      priorChild = rightChild;

    if (priorChild == leftChild)
    {
      if (isHeapCorrect(cur, leftChild))
        break;
      int tmp = heap[cur];
      heap[cur] = heap[leftChild];
      heap[leftChild] = tmp;

      cur = leftChild;
    }
    else
    {
      if (isHeapCorrect(cur, rightChild))
        break;
      int tmp = heap[cur];
      heap[cur] = heap[rightChild];
      heap[rightChild] = tmp;

      cur = rightChild;
    }
  }
}

int isHeapCorrect(int parent, int child)
{
  if (abs(heap[parent]) < abs(heap[child]))
    return 1;
  else if (abs(heap[parent]) == abs(heap[child]) && heap[parent] < heap[child])
    return 1;
  else
    return 0;
}