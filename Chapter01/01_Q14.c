#include <stdio.h>

int main(void) {
	int n;

	puts("사각형을 출력합니다.");
	printf("입력할 수 : ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}