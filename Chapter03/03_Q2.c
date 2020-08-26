#include <stdio.h>
#include <stdlib.h>

int search(const int array[], int length, int key) {
	int i;

	printf("   |");
	for (i = 0; i < length; i++)
		printf("%3d", i);
	printf("\n---+");
	for (; i > 0; i--)
		printf("---");
	putchar('\n');

	for (i = 0; i < length; i++) {
		printf("   |");
		for (int j = 0; j < i; j++)
			printf("   ");
		puts("  *");
		printf("%3d|", i);
		for (int j = 0; j < length; j++)
			printf("%3d", array[j]);
		putchar('\n');

		if (array[i] == key)		break;
	}

	return i == length ? -1 : i;
}

int main(void) {
	int len, key, idx;
	int *arr;

	puts("선형 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &len);

	arr = calloc(len, sizeof(int));
	for (int i = 0; i < len; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &arr[i]);
	}

	printf("검색값 : ");
	scanf_s("%d", &key);

	idx = search(arr, len, key);
	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%3d(은)는 x[%d]에 존재합니다.\n", key, idx);

	free(arr);

	return 0;
}