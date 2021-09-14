#include <stdio.h>
#include <stdlib.h>

void permutation(int *left, int *chosen, int n, int k);

int main() 
{
	int *people;
	int *temp;
	int n, k;
	
	scanf("%d %d", &n, &k);
	people = (int *)malloc(sizeof(int) * n);
	temp = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		people[i] = i + 1;
	}
	
	permutation(people, temp, n, k);

	printf("<");
	for (int i = 0; i < n-1; i++) {
		printf("%d, ", temp[i]);
	}
	printf("%d>", temp[n-1]);

	free(people);
	free(temp);
}

void permutation(int *left, int *chosen, int n, int k)
{
	int ptr = -1;
	int cnt = 0;
	int chosenCnt = 0;


	while (chosenCnt < n) {
		if (left[(ptr + 1) % n] != 0) {
			++ptr;
			++cnt;
		}
		else ++ptr;


		if (cnt == k) {
			cnt = 0;
			chosen[chosenCnt++] = left[ptr % n];
			left[ptr % n] = 0;
		}
	}
}