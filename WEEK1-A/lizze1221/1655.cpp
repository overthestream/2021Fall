#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    priority_queue <int> S;
    priority_queue <int, vector<int>, greater<int>>L;

    for(int i=0;i<n;i++){
        if(S.size() > L.size()) L.push(arr[i]);
        else S.push(arr[i]);
        
        if(!S.empty() && !L.empty()){
             if(S.top() > L.top()){ 
                int a= S.top();
                int b= L.top();
                S.pop();
                L.pop();
                S.push(b);
                L.push(a);
            }
        }
        cout << S.top() <<"\n";
    }
    return 0;
}
