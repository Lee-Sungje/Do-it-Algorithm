#include <stdio.h>

int max4(int a, int b, int c, int d);

int max4(int a, int b, int c, int d) {
	int max = a;

	max = max > b ? max : b;
	max = max > c ? max : c;
	max = max > d ? max : d;

	return max;
}

int main(void) {
	int a, b, c, d;

	printf("4개의 정수를 입력 : ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);

	printf("최대값 : %d\n", max4(a, b, c, d));

	return 0;
}