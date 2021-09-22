#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    long long result = 0;

    for (int i = 0; i < N; i++){
        int height;
        cin >> height;

        while (!s.empty() && s.top().first < height) {
            result += s.top().second;
            s.pop();
        }
        
        if (s.empty()) s.push({ height, 1 });
        else{
            if (s.top().first == height){
                pair<int, int> cur = s.top();
                s.pop();
                result += cur.second;

                if (!s.empty()) result++;

                cur.second++;
                s.push(cur);
            }
            else{
                s.push({ height, 1 });
                result++;
            }
        }
    }
    cout << result << "\n";
    
    return 0;
}
