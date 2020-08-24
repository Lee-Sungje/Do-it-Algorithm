#include <stdio.h>

int min3(int a, int b, int c);

int min3(int a, int b, int c) {
	int min = a;

	min = min < b ? min : b;
	min = min < c ? min : c;

	return min;
}

int main(void) {
	int a, b, c;

	printf("3개의 정수를 입력 : ");
	scanf_s("%d %d %d", &a, &b, &c);

	printf("최소값 : %d\n", min3(a, b, c));

	return 0;
}