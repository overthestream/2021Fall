#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;

vector<string> ans;
string s = "9876543210";

void dec_num(int index){
    for(int i=1; i<=10; ++i){
        vector<bool> v;
        v.assign(10-i, false);
        v.insert(v.end(), i, true);

        do{
            string tmp;
            for(int j=0; j<10; ++j) if(v[j]) tmp += s[j];
            ans.insert(ans.end(), 1, tmp);
        }while(next_permutation(v.begin(), v.end()));
    }
    return;
}

int main(void){
    int n;

    std::cin >> n;

    if(n >= 1023){
        std::cout << -1;
        return 0;
    }

    else{
        dec_num(n);
        std::cout << ans[n];
        
        for(int i=0; i<ans.size(); ++i){
            std::cout << ans[i] << ' ';
        }
        
        std::cout << ans.size();
    }
    return 0;
}