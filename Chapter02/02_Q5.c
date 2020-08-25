#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void ary_print(int arr[], int n);
void ary_reverse(int arr[], int n);

void ary_print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

void ary_reverse(int arr[], int n) {
	for (int i = 0; i < n / 2; i++) {
		ary_print(arr, n);
		printf("arr[%d]과 arr[%d]를 교환합니다.\n", i, n - i - 1);
		swap(int, arr[i], arr[n - i - 1]);
	}
	ary_print(arr, n);
	puts("역순 정렬을 종료합니다.");
}

int main(void) {
	int *x;
	int nx;

	printf("요소의 개수 : ");
	scanf_s("%d", &nx);

	x = calloc(nx, sizeof(int));

	printf("%d개의 정수를 입력하세요.\n", nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	ary_reverse(x, nx);

	free(x);

	return 0;
}