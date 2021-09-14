#include <stdio.h>

int main()
{
	int queue[5000];
	int n, k, front = 0, rear = 0, cnt = 0;

	int c = 0;
	scanf_s("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
		queue[rear++ % n] = i;

	printf("<");

	while (front != rear)
	{
		int val = queue[front++ % n];
		cnt++;
		if (cnt % k == 0) {
			if (front == rear)
				printf("%d", val);
			else
				printf("%d, ", val);
		}
		else
			queue[rear++ % n] = val;
	}
	printf(">");
	return 0;
}