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
    int N;
    scanf("%d", &N);

    vector <member> v;

    for(int i = 0 ; i < N ; i++){
        member m;
        cin >> m.age >> m.name;
        v.push_back(m);
    }

    stable_sort(v.begin(), v.end(), comp);

    vector <member> ::iterator iter;

    for(iter = v.begin() ; iter != v.end() ; iter++){
            cout << iter -> age << " " << iter -> name << endl;
    }

    return 0;
}