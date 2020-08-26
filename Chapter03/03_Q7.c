#include <stdio.h>
#include <stdlib.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size,
	int(*compar)(const void *, const void *));
int intcmp(const int *x, const int *y);

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size,
	int(*compar)(const void *, const void*)) {

	for (size_t i = 0; i < nmemb; i++)
		if (!compar((int *)base + i, key))
			return ((int *)base + i);

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

	puts("seqsearch 함수를 사용하여 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &len);

	arr = calloc(len, sizeof(int));
	for (int i = 0; i < len; i++) {
		printf("arr[%d] : ", i);
		scanf_s("%d", &arr[i]);
	}

	printf("검색값 : ");
	scanf_s("%d", &key);

	p = seqsearch(&key, arr, len, sizeof(int), (int(*)(const void*, const void*))intcmp);
	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 arr[%d]에 존재합니다.", key, (int)(p - arr));
	
	free(arr);

	return 0;
}