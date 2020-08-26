#include <stdio.h>
#include <stdlib.h>

long lngcmp(const long *x, const long *y) {
	if (*x < *y)
		return 1;
	else if (*x > *y)
		return -1;
	else
		return 0;
}

int main(void) {
	long len, key;
	long *arr;
	long *p;

	puts("bsearch 함수를 사용하여 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &len);

	arr = calloc(len, sizeof(long));

	puts("내림차순으로 입력하세요.");
	printf("arr[0] : ");
	scanf_s("%d", &arr[0]);
	for (int i = 1; i < len; i++) {
		do {
			printf("arr[%d] : ", i);
			scanf_s("%d", &arr[i]);
		} while (arr[i] > arr[i - 1]);
	}

	printf("검색값 : ");
	scanf_s("%d", &key);

	p = bsearch(&key, arr, len, sizeof(long), (long(*)(const void*, const void*))lngcmp);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 arr[%d]에 존재합니다.", key, (long)(p - arr));

	free(arr);

	return 0;
}