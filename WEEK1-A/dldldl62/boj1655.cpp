#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int n, x, size=0;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;

    std::cin >> n;

    for(int i=0; i<n; ++i){
        std::cin >> x;
        if(i==0) maxheap.push(x);
        else{
            if(x>=maxheap.top()) minheap.push(x);
            else maxheap.push(x);
        }

        size = maxheap.size()-minheap.size();
        if(size>1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (size<-1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
        std::cout << maxheap.top() << '\n';
    }

    return 0;
}