#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <deque>
using namespace std;

//index, value
deque<pair<int, int>> dq;



int main()
{
    int N, L;
    scanf("%d%d", &N, &L);
    for (int i = 0; i < N; ++i) {
        int a;
        scanf("%d", &a);

        //i-L+1 ~ i 까지의 원소만 남긴다.
        if (!dq.empty() && dq.front().first < i - L + 1) { //i가 하나씩 들어오기 때문에 while문을 사용하지 않아도 된다.
            dq.pop_front();
        }


        //dq 삽입, 정렬
        if (dq.empty()) {
            dq.push_back(make_pair(i, a));

        }
        else { //dq가 비어있지 않을 때
            while (!dq.empty() && dq.back().second > a) { //a가 가장 작은 숫자가 들어오는 경우 dq가 모두 비워지기 때문에 조심. while문이어서 또 검사해줘야함. 등호는 없어야 한다.
                dq.pop_back();
            }
            dq.push_back(make_pair(i, a));
        }

        printf("%d ", dq.front().second);

    }

}
