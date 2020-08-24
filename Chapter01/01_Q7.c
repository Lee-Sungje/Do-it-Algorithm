#include <stdio.h>

int main(void) {
	int i, n;
	int sum;
	puts("1부터 n까지의 합을 구합니다.");
	printf("n 값 : ");
	scanf_s("%d", &n);

	sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
		if (i != n)
			printf("%d + ", i);
	}
	printf("%d = %d\n", n, sum);

	return 0;
}