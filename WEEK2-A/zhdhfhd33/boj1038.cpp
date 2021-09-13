
//시간초과 난 코드 이런 무식한 방법으로는 안되는 듯.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int isDecreasing(const char* str) {
    for (int i = 0; i < strlen(str)-1; ++i) {
        if (str[i] <= str[i + 1]) return 0;
    }
    return 1;
}

int main() { 
    int N;
    scanf("%d", &N);

    char buf[8] = {0};
    

    int count = 0;
    long long i = 0;
    while ((long long)count <= N) {
        if (i == 9876543210) {
            printf("-1");
            return 0;
        }
        snprintf(buf, sizeof(buf), "%lld", i);
        int res = isDecreasing(buf);
        if (res == 1) {
            ++count;
        }

        ++i;
    }
    printf("%s", buf);
    return 0;
}
