#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define MAX 100001
#define MIN - 100001
using namespace std;


int main() {
    priority_queue<int, vector<int>, greater<int>> minPQ; //less<>는 functor
    priority_queue<int, vector<int>, less<int>> maxPQ;
    minPQ.push(MAX);
    maxPQ.push(MIN);//PQ에 아무것도 들어있지 않을 때 top()을 호출하면 runtime에러 뜨더라

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        if (minPQ.size() <= maxPQ.size()) {
            if (num < maxPQ.top()) { //minPQ에 넣어야할 때
                int temp = maxPQ.top();
                maxPQ.pop();
                maxPQ.push(num);
                minPQ.push(temp);
            }
            else {

            minPQ.push(num);
            }
        }
        else {
            if (num > minPQ.top()) { //maxPQ에 넣어야 할 때
                int temp = minPQ.top();
                minPQ.pop();
                minPQ.push(num);
                maxPQ.push(temp);
            }
            else {

                maxPQ.push(num);
            }
           
        }



        printf("%d\n", maxPQ.size() < minPQ.size() ? minPQ.top() : min(minPQ.top(), maxPQ.top()));
    }
    
}