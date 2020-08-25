#include <stdio.h>
#include <stdlib.h>

void ary_print(int arr[], int n);
void ary_copy(int a[], const b[], int n);

void ary_print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

void ary_copy(int a[], const b[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

int main(void) {
	int *x, *y;
	int n;

	printf("요소의 개수 : ");
	scanf_s("%d", &n);

	x = calloc(n, sizeof(int));
	y = calloc(n, sizeof(int));

	printf("%d개의 정수를 입력하세요.\n", n);
	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	ary_copy(y, x, n);
	ary_print(y, n);

	free(x);
	free(y);

	return 0;
}