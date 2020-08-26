#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int n, int key) {
	int i;
	arr[n] = key;

	for (i = 0; i <= n; i++)
		if (arr[i] == key)	break;

	return i == n ? -1 : i;
}

int main(void) {
	int i, nx, ky, idx;
	int *x;

	puts("선형 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	x = calloc(nx + 1, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	printf("검색값 : ");
	scanf_s("%d", &ky);

	idx = search(x, nx, ky);
	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);

	free(x);

	return 0;
}