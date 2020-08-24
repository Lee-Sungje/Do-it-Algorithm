#include <stdio.h>

int min4(int a, int b, int c, int d);

int min4(int a, int b, int c, int d) {
	int min = a;

	min = min < b ? min : b;
	min = min > c ? min : c;
	min = min > d ? min : d;

	return min;
}

int main(void) {
	int a, b, c, d;

	printf("4개의 정수를 입력 : ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);

	printf("최소값 : %d\n", min4(a, b, c, d));

	return 0;
}