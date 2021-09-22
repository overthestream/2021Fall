#include <stdio.h>
#include <stdlib.h>
int main(){
    int N;
    scanf("%d", &N);

    int *sticks = malloc(sizeof(int) * N);

    int currentstick;

    for(int i = 0 ; i < N ; i++){
        scanf("%d", &currentstick);
        sticks[i] = currentstick;
    }

    int seenSticks, highestStick;
    seenSticks = 1;
    highestStick = sticks[N - 1];

    for(int i = ( N - 1 ) ; i >= 0 ; i--){
        if (sticks[i] > highestStick){
            seenSticks++;
            highestStick = sticks[i];
        }
    } 

    printf("%d", seenSticks);

    return 0;
}