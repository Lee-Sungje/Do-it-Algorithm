#include <stdio.h>
#include <stdlib.h>

int bin_search(const int array[], int length, int key) {
	int i;
	int pl = 0;
	int pr = length - 1;
	int pc;

	printf("   |");
	for (i = 0; i < length; i++)
		printf("%3d", i);
	printf("\n---+");
	for (; i > 0; i--)
		printf("---");
	putchar('\n');

	do {
		pc = (pl + pr) / 2;
		printf("   |");
		for (int j = 0; j <= pr; j++) {
			if (j == pc)			printf("  +");
			else if (j == pl)		printf("<- ");
			else if (j == pr)		printf(" ->");
			else					printf("   ");
		}
		printf("\n%3d|", pc);
		for (int j = 0; j < length; j++)
			printf("%3d", array[j]);
		putchar('\n');

		if (array[pc] == key)		return pc;
		else if (array[pc] < key)	pl = pc + 1;
		else							pr = pc - 1;
	} while (pl <= pr);

	return -1;
}

int main(void) {
	int len, key, idx;
	int *arr;

	puts("이진 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &len);

	arr = calloc(len, sizeof(int));
	puts("오른차순으로 입력하세요.");
	printf("arr[0] : ");
	scanf_s("%d", &arr[0]);
	for (int i = 1; i < len; i++) {
		do {
			printf("arr[%d] : ", i);
			scanf_s("%d", &arr[i]);
		} while (arr[i] < arr[i - 1]);
	}
	
	printf("검색값 : ");
	scanf_s("%d", &key);
		
	idx = bin_search(arr, len, key);
	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n", key, idx);
		
	free(arr);

	return 0;
}