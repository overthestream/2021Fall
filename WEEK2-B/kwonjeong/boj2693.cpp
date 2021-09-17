// BOJ 2693번 : N번쨰 큰 수
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        vector<int> v(10); // 크기가 10인 벡터 생성
        for(int j = 0; j < 10; j++)
            cin >> v[j]; // 수 입력받음
        sort(v.begin(), v.end(), greater<int>()); // 내림차순으로 정렬
        cout << v[2] << "\n"; // 3번째 수 출력
    }
}
