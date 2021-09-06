#include <stdio.h>
int maxheap[100001];
int cnt = 0;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int val) {  // 최대힙이 되도록 삽입
	int i = ++cnt;
	while ((i != 1) && val > maxheap[i / 2]) {
		maxheap[i] = maxheap[i / 2];
		i /= 2;
	}
	maxheap[i] = val;
}

int delete() {  // 최대힙이 되도록 정렬 후 return
	if (cnt == 0) return 0;
	int root = maxheap[1];
	maxheap[1] = maxheap[cnt--];
	int parent = 1, child;

	while (1) {
		child = parent * 2;
		if ((child + 1 <= cnt) && maxheap[child] < maxheap[child + 1]) child++;
		if (child > cnt || maxheap[parent] > maxheap[child]) break;

		swap(&maxheap[parent], &maxheap[child]);
		parent = child;
	}
	return root;
}

int main() {
	int n, x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", delete());
		}
		else {
			insert(x);
		}
	}
	return 0;
}