﻿#include <stdio.h>

int main(void) {
	int n, sum;

	puts("1부터 n까지의 합을 구합니다.");
	printf("n : ");
	scanf_s("%d", &n);

	sum = (1 + n) * 5;
	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

	return 0;
}