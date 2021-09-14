#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;

    std::cin >> n;

    for(int i=0; i<n; ++i){
        std::cin >> x;
        if(maxheap.size() == 0) maxheap.push(x);
        else{ // 이 이후를 묶어주지 않아서 seg fault가 계속났다...
            if( maxheap.size() > minheap.size() ) minheap.push(x);
            else maxheap.push(x);

            if(maxheap.top() > minheap.top()){
                int maxtop = minheap.top();
                minheap.pop();
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(maxtop);
            }
        }
        std::cout << maxheap.top() << '\n';
    }

    return 0;
}