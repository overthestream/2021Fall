#include <stdio.h>

int main() {
	int input[4];
	int selecSort[4];
	int i, j, max, index;

	for (i = 0; i < 4; i++) {
		scanf("%d", &input[i]);
	}

	max = input[0];

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (max <= input[j]) {
				max = input[j];
				index = j;
			}
		}
		selecSort[i] = input[index];
		input[index] = -1;
		max = 0;
	}

	printf("%d", selecSort[1] * selecSort[3]);
	return 0;
}