#include <stdio.h>
#include <stdlib.h>

int bin_search2(const int array[], int length, int key) {
	int pl = 0;
	int pr = length - 1;
	int pc;

	do {
		pc = (pl + pr) / 2;

		if (array[pc] == key) {
			while (array[--pc] == key) {}
			return pc + 1;

		} else if (array[pc] < key) {
			pl = pc + 1;
		} else {
			pr = pc - 1;
		}
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
		
	idx = bin_search2(arr, len, key);
	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n", key, idx);
		
	free(arr);

	return 0;
}