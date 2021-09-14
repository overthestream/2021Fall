#include <bits/stdc++.h>

using namespace std;

int mapN[9][9];
int check = 0;
vector<pair<int, int>> pos;

void isValid(int cnt);
bool checkMap(int x, int y);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> mapN[i][j];
            if (mapN[i][j] == 0)
            {
                pos.push_back({i, j});
                check++;
            }
        }
    }

    isValid(0);

    return 0;
}

void isValid(int cnt)
{
    if (cnt == check)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << mapN[i][j] << " ";
            cout << "\n";
        }
        exit(0);
    }

    for (int i = 1; i <= 9; i++)
    {
        int col, row;
        col = pos[cnt].first;
        row = pos[cnt].second;

        mapN[col][row] = i;

        if (checkMap(col, row))
            isValid(cnt + 1);

        mapN[col][row] = 0;
    }
}

bool checkMap(int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (mapN[x][y] == mapN[x][i] && y != i)
        {
            return false;
        }
        if (mapN[x][y] == mapN[i][y] && x != i)
        {
            return false;
        }
    }

    for (int i = x / 3 * 3; i < x / 3 * 3 + 3; i++)
    {
        for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++)
        {
            if (mapN[x][y] == mapN[i][j] && x != i && y != j)
            {
                return false;
            }
        }
    }
    return true;
}