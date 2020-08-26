#include <stdio.h>
#include <stdlib.h>

void *binsearch(const void *key, const void *base, size_t nmemb,
	size_t size, int(*compar)(const void *, const void *));
int intcmp(const int *x, const int *y);

void *binsearch(const void *key, const void *base, size_t nmemb,
	size_t size, int(*compar)(const void *, const void *)) {
	
	size_t left = 0;
	size_t right = nmemb - 1;

	do {
		size_t center = (left + right) / 2;
		int cmp = compar((int *)base + center, key);
		if (cmp == 0)
			return (int *)base + center;
		else if (cmp < 0)
			left = center + 1;
		else
			right = center - 1;
	} while (left <= right);

	return NULL;
}

int intcmp(const int *x, const int *y) {
	if (*x < *y)
		return -1;
	else if (*x > *y)
		return 1;
	else
		return 0;
}

int main(void) {
	int len, key;
	int *arr;
	int *p;

	puts("binsearch 함수를 사용하여 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &len);

	arr = calloc(len, sizeof(int));

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

	p = binsearch(&key, arr, len, sizeof(int), (int(*)(const void *, const void *))intcmp);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 arr[%d]에 존재합니다.\n", key, (int)(p - arr));

	free(arr);

	return 0;
}