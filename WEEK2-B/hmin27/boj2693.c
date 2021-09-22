#include <stdio.h>
#include<stdlib.h>
void thirdBiggest(int *line, int *third, int cnt);

int main() {
	int lineNumber;
	int line[10];
	int *third;
	int i, j;

	scanf("%d", &lineNumber);

	third = (int *)malloc(sizeof(int) * lineNumber);
	
	for (j = 0; j < lineNumber; j++) {
		for (i = 0; i < 10; i++) {
			scanf("%d", &line[i]);
		}

		thirdBiggest(line, third, j);
	}

	for (i = 0; i < lineNumber; i++) printf("%d\n", third[i]);

	return 0;
}

void thirdBiggest(int *line, int *third, int cnt) {
	int max = 1;
	int i, j, index;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 10; j++) {
			if (max <= line[j]) {
				max = line[j];
				index = j;
			}
		}

		if (i == 2) third[cnt] = line[index];
		else {
			line[index] = 0;
			max = 1;
		}

	}
}