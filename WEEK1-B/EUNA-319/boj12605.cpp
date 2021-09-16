#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Word{
public:
    string words;
};

int main() {
    Word stack[52];
    int top = -1;
    string str;
    int n;
    cin>>n;
    cin.ignore();

    for(int i=0;i<n;i++) {// t는 5로 고정이긴 함
        getline(cin, str);
        //받은 입력을 C의 형식으로 char buffer에 넣어주기 위한 변수선언
        char* str_buff = new char[52];

        //받은 입력 string a를 str_buff에 넣어준다.
        strcpy(str_buff, str.c_str());

        //strtok이 포인터를 반환하기때문에 tok을 포인터로 선언. 띄어쓰기를 기준으로 나눔
        char* tok = strtok(str_buff, " ");

        //tok을 살피며 끝이 아니라면 계속 진행한다.
        while (tok != nullptr) {

            //stack에 값을 추가한다.
            stack[++top].words = string(tok);

            //띄어쓰기를 기준으로 나누어 다음 문자를 tok에 저장
            tok = strtok(nullptr, " ");
        }
        cout<<"Case #"<<i+1<<": ";
        while(top>-1){
            cout<<stack[top--].words<<" ";
        }
        cout<<endl;
    }
    return 0;
}
