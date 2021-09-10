#include <stdio.h>
#include <string.h>

void reverse(int tc, char *arr) {
	printf("Case #%d : ", tc+1);
	int i, j, len = strlen(arr);
	for (i = len - 2; i >= 0; i--) {
		if (arr[i] == ' ' || i == 0) {
			if (i == 0) i = -1;
			else  arr[i] = '\0';
			for (j = i + 1; arr[j] != '\0'; j++)
				printf("%c", arr[j]);
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
	int n;
	scanf_s("%d", &n);
	char str[26] = { 0, };
	gets(str);
	for (int i = 0; i < n; i++) {
		gets(str);
		reverse(i, str);
	}
	return 0;
}
