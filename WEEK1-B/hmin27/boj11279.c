#include <stdio.h>
#include <stdlib.h>

void push(int *heap, int elem, int *size);
void pop(int *heap, int *size);
void upheapsort(int *heap, int *size);
void downheapsort(int *heap, int *size);
int compareSize(int a, int b);

int main()
{
	int *buffer;
	int bufferSize;
	int opt;
	int *size, tempSize = 0;
	
	size = &tempSize;

	scanf("%d", &bufferSize);
	buffer = (int *)malloc(sizeof(int) * bufferSize);

	for (int i = 0; i < bufferSize; i++) {
		scanf("%d", &opt);
		opt != 0 ? push(buffer, opt, size) : pop(buffer, size);
	}

	return 0;
}

void push(int *heap, int elem, int *size)
{
	heap[++(*size)] = elem;
	upheapsort(heap, size);
}

void pop(int *heap, int *size) 
{
	if (*size == 0) printf("0\n");
	else {
		printf("%d\n", heap[1]);
		heap[1] = heap[*size];
 		--*(size);

		downheapsort(heap, size);
	}
}

void upheapsort(int *heap, int *size)
{
	int temp;
	int tempSize = *size;
	while (tempSize != 1) {
		if (compareSize(heap[tempSize / 2], heap[tempSize])) {
			temp = heap[tempSize];
			heap[tempSize] = heap[tempSize / 2];
			heap[tempSize / 2] = temp;

			tempSize /= 2;
		}
		else break;
	}
}
void downheapsort(int *heap, int *size) 
{
	int i = 1;
	int compareChildren;
	int temp;

	while (i * 2 <= *size) {
		if (i * 2 == *size) compareChildren = i * 2;
		else {
			if (compareSize(heap[i * 2], heap[i * 2 + 1])) compareChildren = i * 2 + 1;
			else compareChildren = i * 2;
		}

		if (heap[i] > heap[compareChildren]) break;
		else {
			temp = heap[i];
			heap[i] = heap[compareChildren];
			heap[compareChildren] = temp;

			i = compareChildren;
		}
	}
}

int compareSize(int a, int b) {
	if (a < b) return 1;
	else return 0;
}
