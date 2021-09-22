#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int isDecreasing(long long a) { //decreasing이면 -1을 반환. 아니면 i와 i+1이 다른 index를 반환
    char str[11];

    sprintf(str, "%lld", a);
    for (int i = 0; i < strlen(str) - 1; ++i) {
        if (str[i] <= str[i + 1]) return i; //decreasing 아닐 때
    }
    return -1;//decreasing일 때
}
//각 숫작들이 정확히 1씩 차이나는지를 확인.
int findIndex(long long a) {  //정확히 1씩 차이난다면 -1반환. 아니라면 인덱스 반환. 한자리수일 때는 0반환.
    char str[11];
    sprintf(str, "%lld", a);
    const int LEN = strlen(str);
    if (LEN == 1) {
        return 0;
    }
    for (int i = LEN - 1; i > 0; --i) {
        if (str[i - 1] != str[i] + 1) return i;
    }
    return -1;
}

int get10Num(int a) {
    int res = 1;
    while (a--) {
        res *= 10;
    }
    return res;
}

int main() {
    int N;
    scanf("%d", &N);
    int count = 0;
    long long i = 0;
    long long answer = 0;
    for (; count <= N; ) {
        if (i > 9876543210) {
            printf("-1");
            return 0;
        }
        int res = isDecreasing(i);

        if (res == -1) {
            //printf("decrease [%d]: %lld\n", count, i);
            answer = i;
            ++count;
            ++i;
        }
        else {

            --i; //i 원상복구
            char str[11];
            sprintf(str, "%lld", i);


            int add = 1;
            const int LEN = strlen(str);
            for (int j = 0; j < LEN - res - 1; ++j) {
                add *= 10;
            }
            i += add;
            sprintf(str, "%lld", i);

            //필요한 자릿수 만큼 더하고 그 밑은 전부 decreasing 중 가장 작은 값으로 채워야 한다.
            for (int j = LEN - 1, a = 0; j >= res + 1; --j, ++a) {
                str[j] = '0' + a;
                //printf("in for str : %s\n", str);
            }
            sscanf(str, "%lld", &i);

        }

    }
    printf("%lld", answer);
    return 0;
}
