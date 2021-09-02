#include <iostream>
#include <queue>
using namespace std;

int arr[10001];
priority_queue <int> S;
priority_queue <int> L;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++){
        if(S.size() == L.size()) L.push(arr[i]);
        else S.push(arr[i]);

        if(!S.empty()){
            if(S.size() > L.size()) cout << S.top() <<"\n";
            else{
                int a= S.top();
                int b= L.top();
                if(a<b) cout << a <<"\n";
                else cout << b <<"\n";
            }
        }
    }
    return 0;
}
