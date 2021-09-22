#include <stdio.h>

int N, M, H;

int MAP[30 + 5][10 + 5];

void input()
{
	scanf("%d %d %d", &N, &M, &H);

	for (int r = 0; r <= H + 1; r++)
		for (int c = 0; c <= N + 1; c++)
			MAP[r][c] = 3; /* 벽 설치 */

	for (int r = 1; r <= H; r++)
		for (int c = 1; c <= N; c++)
			MAP[r][c] = 0;

	for (int i = 0; i < M; i++)
	{
		int r, c;

		scanf("%d %d", &r, &c);

		MAP[r][c] = 1;
		MAP[r][c + 1] = 2;
	}

	return;
}

void output()
{
	for (int r = 0; r <= H + 1; r++)
	{
		for (int c = 0; c <= N + 1; c++)
			printf("%d ", MAP[r][c]);
		putchar('\n');
	}
}

int check()
{
	for (int ladder = 1; ladder <= N; ladder++)
	{
		int sr, sc;

		sr = 1;
		sc = ladder;

		while (1)
		{
			if (sr == H + 1) break;

			if (MAP[sr][sc] == 0) sr++;
			else
			{
				if (MAP[sr][sc] == 1) sc++, sr++;
				else sc--, sr++;
			}
		}

		if (ladder != sc) return 0;
	}

	return 1;
}

int PASS = 0;
void DFS(int L, int sr, int max)
{
	if (L == max)
	{
		// output();
		if (check()) PASS = 1;
		return;
	}

	for (int r = sr; r <= H; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (MAP[r][c] == 1 || MAP[r][c] == 2 
				|| MAP[r][c + 1] == 1 || MAP[r][c + 1] == 3) continue;

			MAP[r][c] = 1;
			MAP[r][c + 1] = 2;

			DFS(L + 1, r, max);

			MAP[r][c] = 0;
			MAP[r][c + 1] = 0;
		}
	}
}

int main(void)
{
	int sr, sc;

	input();

	if (check()) /* 사다리 설치가 필요 없는 경우 */
	{
		printf("0\n");
		return 0;
	}
	
	for (int setup = 1; setup <= 3; setup++)
	{
		DFS(0, 1, setup);

		if (PASS)
		{
			printf("%d\n", setup);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}