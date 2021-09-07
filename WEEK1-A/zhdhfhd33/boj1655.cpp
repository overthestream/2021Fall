#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define MAX 100001
using namespace std;


int main() {
    priority_queue<int, vector<int>, less<int>> minPQ; //less<>는 functor
    priority_queue<int, vector<int>, greater<int>> maxPQ; 
    //printf("%d", minPQ.size());
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        if (minPQ.size() <= maxPQ.size()) {
            minPQ.push(num);
        }
        else {
            maxPQ.push(num);
        }


        int fromMinPQ, fromMaxPQ;
        
        if (minPQ.size() == 0) {
            fromMinPQ = MAX;
        }
        else {
            fromMinPQ = minPQ.top();;
        }
        if (maxPQ.size() == 0) {
            fromMaxPQ = MAX;
        }
        else {
            fromMaxPQ = maxPQ.top();
        }

        printf("%d\n", fromMinPQ > fromMaxPQ ? fromMaxPQ : fromMinPQ);
    }
    
}