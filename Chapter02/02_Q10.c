#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void ary_print(int arr[], int n);
void shuffle(int a[], int n);

void ary_print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

void shuffle(int a[], int n) {
	int rnd;

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		rnd = rand() % n;
		swap(int, a[i], a[rnd]);
	}
}

int main(void) {
	int *x;
	int n;

	printf("요소의 개수 : ");
	scanf_s("%d", &n);

	x = calloc(n, sizeof(int));

	printf("%d개의 정수를 입력하세요.\n", n);
	for (int i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	shuffle(x, n);
	ary_print(x, n);

	free(x);

	return 0;
}