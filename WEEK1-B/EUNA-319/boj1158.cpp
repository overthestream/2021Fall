#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }

    cout<<"<";

    int top=0,i=0;

    while(!q.empty()) {
        if (top % k != (k-1)){
            q.push(q.front());
            q.pop();
        }
        else {
            cout << q.front();
            if(i<n-1) {
                cout<<", ";
                i++;
            }
            q.pop();
        }
        top++;
    }
    cout<<">";

    return 0;
}