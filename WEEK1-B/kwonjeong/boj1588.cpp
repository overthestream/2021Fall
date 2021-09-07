// BOJ 1588번 : 요세푸스 문제
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k; // n: 사람 수 / k: k번째 사람 제거
    cin >> n >> k;
    queue <int> q; // q 생성
    int count = 1; // 전체 숫자 세는 변수
    int result = 1; // 순열 출력이 얼마나 되었는지 측정 변수

    for(int i = 1; i <= n; i++){
        q.push(i); // 큐에 순서대로 숫자 저장
    }

    cout << "<";
    while(q.size()){ // 큐에 원소가 존재할 때
        if(count % k == 0){ // 숫자 출력 (k번째)
            if(result == n){ // 만약 출력 마지막 원소라면
                cout << q.front() << ">"; // 출력하고 닫아줌
                break; // 반복문 종료
            }
            cout << q.front() << ", "; // 원소 출력해 줌
            q.pop(); // 출력한 원소는 제거
            result++; // 출력했으므로 result 증가
        }
        else{ // 출력할 때가 아니라면
            q.push(q.front()); // 맨 앞 원소를 다시 뒤에 추가
            q.pop(); // 뒤에 추가했으므로 맨 앞 원소 제거
        }
        count++; // count 변수 증가
    }
}
