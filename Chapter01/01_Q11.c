#include <stdio.h>

int main(void) {
	int n, i;

	do {
		printf("양의 정수를 입력 : ");
		scanf_s("%d", &n);
	} while (n <= 0);

	for (i = 0; n > 0; i++)
		n /= 10;

	printf("그 수는 %d자리입니다.\n", i);

	return 0;
}