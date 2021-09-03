#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, max, cnt = 1;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	max = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > max) {
			cnt++;
			max = arr[i];
		}
	}
	printf("%d", cnt);
	return 0;
}