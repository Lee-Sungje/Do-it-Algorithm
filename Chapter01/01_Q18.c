#include <stdio.h>

void nrpira(int n);

void nrpira(int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++)
			printf("  ");

		for (j = i; j < (n * 2) - (i + 1); j++)
			printf("%2d", i + 1);

		putchar('\n');
	}
}

int main(void) {
	int n;

	do {
		printf("몇 단 피라미드입니까? : ");
		scanf_s("%d", &n);
		if (n <= 0)
			puts("양의 정수를 입력!");
	} while (n <= 0);

	nrpira(n);

	return 0;
}