#include <iostream>

using namespace std;
//using selection sort
//1st * 3nd -> space
int main(){
    int first, second, third, fourth;
    int num[4] = {0,};

    scanf("%d%d%d%d", &first, &second, &third, &fourth);
    num[0] = first;
    num[1] = second;
    num[2] = third;
    num[3] = fourth;

    int minKey;
    int temp;

    for(int i = 0 ; i < 3 ; i++){
        minKey = i;
        for(int j = i + 1 ; j < 4 ; j++){
            if (num[j] < num[minKey]){
                minKey = j;
            }
        }
        temp = num[i];
        num[i] = num[minKey];
        num[minKey] = temp;

    }
    

    printf("%d", num[0] * num[2]);
    return 0;
}