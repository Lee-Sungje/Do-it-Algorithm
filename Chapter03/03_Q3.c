#include <stdio.h>
#include <stdlib.h>

int search_idx(const int array[], int length, int key, int index[]) {
	int counter = 0;

	for (int i = 0; i < length; i++)
		if (array[i] == key)
			index[counter++] = i;

	return counter;
}

int main(void) {
	int len, key, cnt;
	int *arr, *idx;

	puts("선형 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &len);

	arr = calloc(len, sizeof(int));
	idx = calloc(len, sizeof(int));
	for (int i = 0; i < len; i++) {
		printf("arr[%d] : ", i);
		scanf_s("%d", &arr[i]);
	}

	printf("검색값 : ");
	scanf_s("%d", &key);

	cnt = search_idx(arr, len, key, idx);
	if (cnt == 0)
		printf("검색에 실패했습니다.\n");
	else
		for (int i = 0; i < cnt; i++)
			printf("%d(은)는 arr[%d]에 존재합니다.\n", key, idx[i]);

	free(arr);
	free(idx);

	return 0;
}