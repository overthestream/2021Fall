#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  stack<int> descend;
  int result = 0;

  for (int i = 0; i < N; ++i)
  {
    int temp;
    cin >> temp;

    if (descend.empty())
    {
      descend.push(temp);
      continue;
    };

    while (descend.top() < temp)
    {
      descend.pop();
      ++result;
      if (descend.empty())
        break;
    }

    result += descend.size();
    descend.push(temp);
  }
  cout << result;
}
