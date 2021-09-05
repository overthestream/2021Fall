#include <iostream>
#include<algorithm>
//#include<stack> 사용해서 풀 수도 있음
using namespace std;

int top=-1;
int stack[100000];// 막대기의 최대 개수


int main() {
    int tc=0,num=0;
    int count=0, pre=0, com=0;
    cin>>tc;
    cin.ignore();

    for(int i=0;i<tc;i++){// 막대기의 개수만큼 입력받기
        cin>>num;
        cin.ignore(); // 입력 받고 버퍼를 비워주어야 함
        stack[++top]=num;
    }

    com=stack[top--]; // 오른쪽 기준 가장 가까운 막대기의 높이 반환
    count++;
    while(top>-1){
        pre = stack[top--];
        if(com<pre) {// pre가 비교 숫자 com보다 높거나 같다면
            count++; // 개수 증가
            com = pre; // com update
        }
    }

    cout<<count<<endl;
    return 0;
}
