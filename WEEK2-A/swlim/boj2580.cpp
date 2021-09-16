#include <bits/stdc++.h>

using namespace std;

int arr[9][9];
vector<pair<int, int>> Vec;

bool check(int y, int x, int i) 
{
    for (int k = 0; k < 9; k++) 
    {
        if (arr[y][k] == i || arr[k][x] == i)
            return false;
    }
    
    for (int k = (y / 3) * 3; k < (y / 3) * 3 + 3; k++)   
    {
        for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
        {
            if (arr[k][j] == i)
            return false;
        }
    }

    return true;
}

bool dfs(int n)
{
    if (n == Vec.size())
        return true;
   
    int y = Vec[n].first;
    int x = Vec[n].second;

    for (int i = 1; i <= 9; i++) 
    {
        if (check(y, x, i))
        {
            arr[y][x] = i;

            if (dfs(n + 1))
                return true;

            arr[y][x] = 0;
        }
    }

    return false;
}

int main()
{
    // 입력 속도 업
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    for (auto & i : arr) for (int & j : i) cin >> j;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)
                Vec.push_back({i, j});
        }
    }

    dfs(0);

    cout << endl;
    
    for (auto & i : arr)
    {
        for (int & j : i) cout << j << ' ';
        cout << endl;
    }

    return 0;
}