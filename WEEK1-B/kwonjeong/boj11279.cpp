// BOJ11279번 : 최대 힙
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> maxH;
    int n, elem;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> elem;
        maxH.push(elem);
        if(elem == 0){
            cout << maxH.top() << "\n";
            maxH.pop();
        }
    }
}
