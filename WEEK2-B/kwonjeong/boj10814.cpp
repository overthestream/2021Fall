// BOJ 10814번 : 나이순 정렬
#include <iostream>
#include <algorithm>
#include <vector>
 using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    // 사용자 정렬기준(첫번째 원소를 기준으로 오름차순)
    if(a.first < b.first)
        return true;
    else
        return false;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> v(n); // 나이와 이름을 담을 벡터 생성

    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    // compare함수를 이용해 같은 값일 때 들어온 순서대로 정렬하게 함
    stable_sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
