#include <bits/stdc++.h>
using namespace std;

int _map[9][9];
int finish = 0;
void DFS(int x, int y);
bool checkRow(int a);
bool checkCol(int a);
bool checkBox(int a, int b);

void printMap()
{
    cout << "\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << _map[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> _map[i][j];
        }
    }
    DFS(0, 0);
    printMap();
}

void DFS(int y, int x)
{

    // cout << "\n****************( " << y << ", " << x << " )*******************\n";
    // printMap();
    // cout << "\n***********************************\n";
    if (_map[y][x] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {

            _map[y][x] = i;
            // cout << "insert " << i << "\n";
            if (!(checkCol(x) && checkRow(y) && checkBox(y, x)))
            {
                _map[y][x] = 0;
            }
            else
            {
                if (x == 8 && y == 8)
                {
                    finish = 1;
                    return;
                }
                else if (x == 8)
                {
                    DFS(y + 1, 0);
                }
                else
                    DFS(y, x + 1);

                if (finish)
                    return;
                _map[y][x] = 0;
            }
        }
    }
    else
    {
        if (x == 8 && y == 8)
        {
            finish = 1;
            return;
        }
        else if (x == 8)
        {
            DFS(y + 1, 0);
        }
        else
            DFS(y, x + 1);
    }
    return;
}

bool checkRow(int a)
{
    int check[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++)
    {
        if (_map[a][i] == 0)
            continue;
        check[_map[a][i] - 1]++;
        if (check[_map[a][i] - 1] > 1)
        {
            // cout << "row False\n";
            return false;
        }
    }
    return true;
}

bool checkCol(int a)
{
    int check[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++)
    {
        if (_map[i][a] == 0)
            continue;
        check[_map[i][a] - 1]++;
        if (check[_map[i][a] - 1] > 1)
        {
            // cout << "Col False\n";
            return false;
        }
    }
    return true;
}

bool checkBox(int a, int b)
{
    int check[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = a / 3 * 3; i < a / 3 * 3 + 3; i++)
    {
        for (int j = b / 3 * 3; j < b / 3 * 3 + 3; j++)
        {
            if (_map[i][j] == 0)
                continue;
            check[_map[i][j] - 1]++;
            if (check[_map[i][j] - 1] > 1)
            {
                // cout << a / 3 * 3 << ", " << b / 3 * 3 << "Box False\n";
                return false;
            }
        }
    }
    return true;
}