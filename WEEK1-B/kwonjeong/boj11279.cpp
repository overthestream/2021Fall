// BOJ11279번 : 최대 힙
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 입출력 빠르게 해 줌
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> maxH; // 최대 힙 생성
    int n, elem; // n: 연산의 개수 / elem: 원소
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> elem; // 원소 입력받음
        maxH.push(elem); // 입력받은 원소 push
        if(elem == 0){ // 원소가 0이라면
            cout << maxH.top() << "\n"; // 최대 힙의 top을 출력
            maxH.pop(); // 출력했으므로 pop 해줌
        }
    }
}
