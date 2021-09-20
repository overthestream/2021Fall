#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v; //감소하는 수를 저장하는 vector

void makeArray(int N, ll sum) //9부터 0까지 감소해가며 포함할지 안할지 선택해가며 vertor에 저장함
{
    if (N == -1) //0까지 다 돌았으면 결과값 v에 저장
    {
        v.push_back(sum);
        return;
    }
    makeArray(N - 1, sum);          //해당 N은 선택 X
    makeArray(N - 1, sum * 10 + N); //해당 N은 선택 O
} //0의 경우 두번 들어가게 됨

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    makeArray(9, 0);
    if (v.size() - 1 < N + 1)
    {
        cout << -1;
    }
    else
    {
        sort(v.begin(), v.end()); //v안에는 크키순서대로 정렬이 안되어있음
        cout << v[N + 1];         //0이 두번 들어가있어서 index 1 부터 시작인데, 문제는 0이 0번쨰 숫자임
    }
    return 0;
}