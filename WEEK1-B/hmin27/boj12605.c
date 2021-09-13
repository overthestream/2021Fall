#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_WORDS 49
#define MAX_ALPHABET 25

int getWord(char* words[]);

int main()
{
	int caseNum;
	int i;
	int lastElem;
	char *words[MAX_WORDS];

	scanf("%d", &caseNum);
	getchar();

	for (i = 0; i < caseNum; i++) {
		lastElem = getWord(words);

		printf("Case #%d:", i + 1);

		for (int j = lastElem - 1; j >= 0; j--) {
			printf(" %s", words[j]);
		}
		printf("\n");
	}


}

int getWord(char* words[]) {
	int i = 0, wordCnt = 0, j = 0;
	int buff = 0, tempCnt = 0;
	char alphabet[MAX_ALPHABET];

	while (1) {
		alphabet[i] = getchar();

		if (alphabet[i] == ' ' || alphabet[i] == '\n') {
			char *temp = (char *)malloc(25 * sizeof(char));

			for (j = buff; j < i; j++) {
				temp[tempCnt++] = alphabet[j];
			}

			temp[tempCnt] = '\0';
			buff = i+1;
			words[wordCnt] = temp;
			wordCnt++;

			tempCnt = 0;

			if (alphabet[i] == '\n') break;
		}

		i++;

	}

	words[wordCnt] = NULL;

	return wordCnt;

}