#include <stdio.h>
#define MAX_SIZE 100000

void inputSize(int stick[], int size);
int countStick(int stick[], int total, int cnt, int large);
int compare(int a, int b);

int main() {
	int stick[MAX_SIZE];
	int total, lastElement;
	int cnt = 1;

	scanf("%d", &total);
	inputSize(stick, total);

	lastElement = stick[total-1];

	cnt = countStick(stick, total, cnt, lastElement);

	printf("%d", cnt);

	return 0;
}

void inputSize(int stick[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		scanf("%d", &stick[i]);
	}
}

int countStick(int stick[], int total, int cnt, int large) {
	int i, comp;

	for (i = total - 2; i >= 0; i--) {
		comp = compare(stick[i], large);
		if (comp) {
			large = stick[i];
			++cnt;
		}
	}

	return cnt;
}

int compare(int a, int b) {
	if (a <= b) return 0;
	else return 1;
}