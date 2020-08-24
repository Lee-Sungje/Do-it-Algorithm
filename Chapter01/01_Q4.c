#include <stdio.h>

int med3(int a, int b, int c);

int med3(int a, int b, int c) {
	if (a >= b)
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
}

int main(void) {
	int a, b, c;

	printf("a값 입력 : ");
	scanf_s("%d", &a);

	printf("b값 입력 : ");
	scanf_s("%d", &b);

	printf("c값 입력 : ");
	scanf_s("%d", &c);

	printf("중간값 : %d\n", med3(a, b, c));

	return 0;
}