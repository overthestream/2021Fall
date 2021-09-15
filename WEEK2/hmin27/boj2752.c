#include <stdio.h>
#define MAX_NUM 3
//1. Current value is bigger than the last element in the sorted array => stay
//2. Current value is smaller then the first element in the sorted array => insert at array[0]
//3. There is a place fit to current value => insert at the place


int main() 
{
	int number[MAX_NUM];
	int i, j, k, temp;
	int insertPos;

	for (i = 0; i < MAX_NUM; i++) {
 		scanf("%d", &number[i]);
	}

	for (i = 1; i < MAX_NUM; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (number[i] > number[i - 1]) break;  //case #01
			else {
				if (number[j] < number[i]) {  //case #03
					insertPos = j+1;
					temp = number[i];
					for (k = i - 1; k > j; k--) {
						number[k + 1] = number[k];
					}
					number[insertPos] = temp;

					break;
				}

				if (j == 0 && number[j] > number[i]) {  //case #02
					temp = number[i];
					for (k = i - 1; k >= j; k--) {
						number[k + 1] = number[k];
					}
					number[j] = temp;
				}

			}

			
		}
	}

	printf("%d ", number[0]);
	printf("%d ", number[1]);
	printf("%d", number[2]);

	return 0;
}