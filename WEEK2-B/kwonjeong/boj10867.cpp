// BOJ 10867번 : 중복 빼고 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end()); // 오름차순으로 정렬
    v.erase(unique(v.begin(), v.end()), v.end()); // 중복된 원소들 제거

    for(auto result : v){
        cout << result << " ";
    }
}
