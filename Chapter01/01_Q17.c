#include <stdio.h>

void spira(int n);

void spira(int n) {
	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++)
			putchar(' ');
		for (j = (i * 2) - 1; j > 0; j--)
			putchar('*');
		putchar('\n');
	}
}

int main(void) {
	int n;

	do {
		printf("몇 단 피라미드입니까? : ");
		scanf_s("%d", &n);
		if (n <= 0)
			puts("1이상의 수를 입력!");
	} while (n <= 0);

	spira(n);

	return 0;
}