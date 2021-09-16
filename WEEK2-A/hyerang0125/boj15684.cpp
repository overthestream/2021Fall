#include <bits/stdc++.h>

using namespace std;

int mlist[11][31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(mlist, 0, sizeof(mlist));

    // n: 세로선의 개수, m: 가로선의 개수(선이 위치할 높이, 연결할 선), h: 사다리 높이
    int n, m, h, temp1, temp2;
    vector<pair<int, int>> mlist;
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        mlist[temp1][temp2] = 1;  // 출발
        mlist[temp1][temp2] = -1; // 도탁
    }

    // i번 출발 -> i번 도착해야 함.
    // 1번부터 사다리를 타고 가며 도착지가 1번이 되도록 사다리를 추가한다. 근데 시간 많이 걸릴거 같음.
    // 그냥 전부 계산한 다음 사다리 하나씩 추가하면서 위치 조정하는게 더 좋을 듯.

    int *arrived = new int[n];
    for (int i = 0; i < n; i++)
    {
    }

    return 0;
}