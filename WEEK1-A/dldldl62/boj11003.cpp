#include<iostream>
#include<queue>
#include <deque>
#include<algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque< pair<int, int> > dq;
    int n, l, x;

    std::cin >> n;
    std::cin >> l;

    for(int i=0; i<n; ++i){
        while(dq.size() > 0 && dq.front().second <= i-l)dq.pop_front();
        std::cin >> x;

        while(dq.size() > 0 && dq.back().first >= x) dq.pop_back();
        dq.push_back( make_pair(x,i) );
        std::cout << dq.front().first << ' ';
    }
    return 0;
}