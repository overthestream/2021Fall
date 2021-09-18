#include <iostream>
#include <set>

using namespace std;

int main(){
    int N, num;
    set <int> s;
    set <int>::iterator iter;

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &num);
        s.insert(num);
    }

    for(iter = s.begin() ; iter != s.end() ; iter++){
        printf("%d ", *iter);
    }
    return 0;
}