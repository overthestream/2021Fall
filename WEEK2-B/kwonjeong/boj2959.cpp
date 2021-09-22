// BOJ 2959번 : 거북이
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[4];
    for(int i = 0; i < 4; i++)
        cin >> arr[i];
    sort(arr, arr + 4); // 배열을 오름차순으로 정렬
    cout << arr[0] * arr[2]; // 그 중에서 제일 큰 수와 세번쨰로 큰 수를 곱한 값을 출력
}
