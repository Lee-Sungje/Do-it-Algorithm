#include <stdio.h>

int main(void) {
	int x, y;

	puts("사각형을 출력합니다.");
	printf("높이 : ");
	scanf_s("%d", &y);
	printf("너비 : ");
	scanf_s("%d", &x);

	for (; y > 0; y--) {
		for (int i = x; i > 0; i--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}