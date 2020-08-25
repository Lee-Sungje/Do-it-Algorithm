#include <stdio.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

int card_conv(int x, int n, char d[]) {
	int digits = 0;
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (x == 0) {
		d[digits++] = dchar[0];
	} else {
		while (x) {
			printf("%2d | %9d ··· %c\n", n, x, dchar[x % n]);
			puts("   + ----------");
			d[digits++] = dchar[x % n];
			x /= n;
		}
		puts("             0 ");
	}
	return digits;
}

void arr_reverse(char arr[], int n) {
	for (int i = 0; i < n / 2; i++)
		swap(char, arr[i], arr[n - i - 1]);
}

int main(void) {
	int num;
	int ch;
	int degree;
	int one_moer;
	char cnum[512];

	puts("10진수를 기수 변환합니다.");
	do {
		do {
			printf("변환하는 음이 아닌 정수 : ");
			scanf_s("%d", &num);
		} while (num <= 0);

		do {
			printf("어떤 진수로 변환할까요?(2-36) : ");
			scanf_s("%d", &ch);
		} while (ch < 2 || ch > 36);

		degree = card_conv(num, ch, cnum);
		arr_reverse(cnum, degree);

		printf("%d진수로 ", ch);
		for (int i = 0; i < degree; i++)
			putchar(cnum[i]);
		puts("입니다.");

		printf("한 번 더 할까요?(1 = 예/0 = 아니오) : ");
		scanf_s("%d", &one_moer);
	} while (one_moer != 0);

	return 0;
}