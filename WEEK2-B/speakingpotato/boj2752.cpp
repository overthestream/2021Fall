#include <iostream>

using namespace std;
//using selection sort
int main(){
    int first, second, third;
    int num[3] = {0,};

    scanf("%d%d%d", &first, &second, &third);
    num[0] = first;
    num[1] = second;
    num[2] = third;

    int minKey;
    int temp;

    for(int i = 0 ; i < 3 ; i++){
        minKey = i;
        for(int j = i + 1 ; j < 3 ; j++){
            if (num[j] < num[minKey]){
                minKey = j;
            }
        }
        temp = num[i];
        num[i] = num[minKey];
        num[minKey] = temp;

    }
    

    printf("%d %d %d\n", num[0], num[1], num[2]);
    return 0;
}