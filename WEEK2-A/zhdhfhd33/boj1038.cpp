#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int isDecreasing(const char* str) { //decreasing이면 -1을 반환. 아니면 i와 i+1이 다른 index를 반환
    for (int i = 0; i < strlen(str) - 1; ++i) {
        if (str[i] <= str[i + 1]) return i; //decreasing 아닐 때
    }
    return -1;//decreasing일 때
}

void resetBuf(char* str) {
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = 0;
    }
}

int isLast(char* temp) {
    for (int i = 0; i < strlen(temp)-1; ++i) {
        if (temp[i] - 1 != temp[i + 1]) return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    char buf[11] = { 0 }; //9876543210을 담기 위한 공간


    int count = 0;
    long long i = 0;
    while ((long long)count <= N) {

        snprintf(buf, sizeof(buf), "%lld", i);
        const int LEN = strlen(buf); //LEN = 자릿수
        int res = isDecreasing(buf);
        if (res == -1) {
            printf("decreasing[%d] : %lld\n", count, i);
            ++count;

            ++i; // i컨트롤

        }
        else {
            //printf("i : %d\n", i);
            

            int add = 1;
            for (int j = 0; j < LEN - res - 1; ++j) {
                add *= 10;
            }
            i += add;
            char temp[11] = { 0 };

            
            snprintf(temp, sizeof(temp), "%lld", i);
            if (res == 0) {

                for (int j = strlen(temp) - 1, a = 0; j >= 1; --j, ++a) { //첫째자리만 빼고 모두 바꿈.
                    temp[j] = 48 + a;
                }
            }
            //printf("before i : %lld\n", i);
            temp[strlen(temp) - 1] = '0';


            sscanf(temp, "%lld\n", &i); //i컨트롤
            //printf("after i : %lld\n", i);
            if (i > 9876543210) {
                printf("-1");
                return 0;
            }

        }

    }
    printf("%s", buf);
    return 0;
}
