#include<iostream>
#include<queue>

using namespace std;

struct compare{
    bool operator()(int a, int b){

        if(abs(a) > abs(b)) return true;
        else if (abs(a) == abs(b)){
            if(a>b) return true;
            else return false;
        }  
        else return false;
    }
};

int main(void){
    int n, x;
    priority_queue<int, vector<int>, compare> abs_q;

    std::cin >> n;
    for(int i=0; i<n; ++i){
        std::cin >> x;
        if(x) abs_q.push(x);
        else {
            if(abs_q.empty()){        
                cout << 0 << '\n';
                continue;
            }
            cout << abs_q.top() << '\n';
            abs_q.pop();
        }
    }

    return 0;
}