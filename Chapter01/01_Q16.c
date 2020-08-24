#include <stdio.h>

void triangleLB(int n);
void triangleLU(int n);
void triangleRU(int n);
void triangleRB(int n);

void triangleLB(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = n - i; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void triangleLU(int n) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = n - i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
}

void triangleRU(int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = i; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void triangleRB(int n) {
	int i, j;
	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = i; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main(void) {
	int n;

	do {
		printf("몇 단 삼각형입니까? : ");
		scanf_s("%d", &n);
		if (n <= 0)
			puts("1이상의 수를 입력!");
	} while (n <= 0);

	puts("왼쪽 아래가 직각인 이등변 삼각형 출력");
	triangleLB(n);

	puts("왼쪽 위가 직각인 이등변 삼각형 출력");
	triangleLU(n);

	puts("오른쪽 위가 직각인 이등변 삼각형 출력");
	triangleRU(n);

	puts("오른쪽 아래가 직각인 이등변 삼각형 출력");
	triangleRB(n);

	return 0;
}