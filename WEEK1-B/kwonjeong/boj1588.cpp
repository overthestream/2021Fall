// 요세푸스 문제
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    queue <int> q;
    int count = 1;
    int result = 1;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    cout << "<";
    while(q.size()){
        if(count % k == 0){
            if(result == n){
                cout << q.front() << ">";
                break;
            }
            cout << q.front() << ", ";
            q.pop();
            result++;
        }
        else{
            q.push(q.front());
            q.pop();
        }
        count++;
    }
}
