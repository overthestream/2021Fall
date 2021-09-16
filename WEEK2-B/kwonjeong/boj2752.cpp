// BOJ 2752번 : 세수정렬
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c; // 수 세개 입력받기
    int temp; // 임시 변수
    if(a > b){ 
        temp = a;
        a = b;
        b = temp;
    }
    if(b > c){
        temp = b;
        b = c;
        c = temp;
    }
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
    cout << a << " " << b << " " << c;
}

