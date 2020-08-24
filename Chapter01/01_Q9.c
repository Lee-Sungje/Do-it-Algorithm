#include <stdio.h>

int sumof(int a, int b);

int sumof(int a, int b) {
	int sum = 0;

	for (int i = a; i <= b; i++)
		sum += i;

	return sum;
}

int main(void) {
	int a, b;
	int sum;

	puts("a부터 b까지의 합을 구합니다.");
	printf("a : ");
	scanf("%d", &a);
	printf("b : ");
	scanf("%d", &b);

	sum = a < b ? sumof(a, b) : sumof(b, a);

	printf("%d부터 %d까지의 합 : %d\n", a, b, sum);

	return 0;
}