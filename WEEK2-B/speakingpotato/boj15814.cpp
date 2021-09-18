#include <iostream>

using namespace std;
//selection sort up to only N, decreasing order
int main(){
    int T;
    scanf("%d",&T);
    int maxKey, temp;
    int num[10] = {0,};
    int nums;

    for(int i = 0 ; i < T ; i++){
        for(int j = 0 ; j < 10 ; j++){
            //scanf("%d", &nums);
            //num[j] = nums;

            scanf("%d", &num[j]);

            //printf("%d ",nums);
        }
        //printf("\n");

        //정리
        for(int k = 0 ; k < 3 ; k++){
            maxKey = k;

            for(int l = k + 1 ; l < 10 ; l++){
                if (num[l] > num[maxKey]){
                    maxKey = l;
                }
            }

            temp = num[k];
            num[k] = num[maxKey];
            num[maxKey] = temp;


            //printf("%d ", num[k]);

        }

        printf("%d\n", num[2]);

    }

    return 0;
}
