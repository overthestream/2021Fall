#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



struct member {
    int age;
    string name;
};
bool comp(const member &P1, const member &P2){
    return P1.age < P2.age;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    int N;
    cin >> N;

    vector <member> v;

    for(int i = 0 ; i < N ; i++){
        member m;
        cin >> m.age >> m.name;
        v.push_back(m);
    }

    stable_sort(v.begin(), v.end(), comp);

    vector <member> ::iterator iter;

    for(iter = v.begin() ; iter != v.end() ; iter++){
            cout << iter -> age << " " << iter -> name << '\n';
    }

    return 0;
}