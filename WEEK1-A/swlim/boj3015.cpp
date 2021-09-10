#include <bits/stdc++.h>

using namespace std;

int main()
{
    //입출력 속도 업
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    cin >> N;
    
    long long ans = 0;
    stack<pair<int, int> > st;                        
    
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        pair<int,int> p = make_pair(temp, 1);                
        
        while(!st.empty())
        {
            if(st.top().first <= temp)
            {               
                ans += (long long)st.top().second;        
                if(st.top().first == temp)            
                    p.second += st.top().second;        
                st.pop();                    
            }
            else
            {
                if(!st.empty())                
                    ans += 1LL;                
                break;                                     
            } 
        }
        st.push(p);                            
    }

    cout << ans;
    return 0;
}