#include<iostream>
#include<stack>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    long long ans = 0;
    stack<pair<int, int> > st;                       

    for (int i = 0; i < n; i++) {
        int high;
        cin >> high;
        pair<int, int> p = make_pair(high, 1);              

        while (!st.empty()) {
            if (st.top().first <= high) {               
                ans += (long long)st.top().second;     
                if (st.top().first == high)           
                    p.second += st.top().second;       
                st.pop();                    
            }
            else {
                if (!st.empty())              
                    ans += 1LL;              
                break;
            }
        }
        st.push(p);                         
    }
    cout << ans;
    return 0;
}
