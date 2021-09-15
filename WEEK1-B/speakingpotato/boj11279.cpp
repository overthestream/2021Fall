#include <iostream>
#include <queue>

using namespace std;

void main(){
    priority_queue<int> maxHeap;


    int N;
    int curr;

    for (int i = 0 ; i < N ; i++){
        cin >> curr;
        if(curr == 0){
            if(maxHeap.empty()){
                cout << curr << endl;
            } else {
                cout << maxHeap.top() << endl;
                maxHeap.pop();
            }

        } else {
            maxHeap.push(curr);
        }

    }

}