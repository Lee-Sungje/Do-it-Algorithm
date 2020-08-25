#include <stdio.h>

#define swap(type, x, y) do{type t = y; y = x; x = t;} while(0)

int card_convr(int x, int n, char d[]);
void ary_reverse(char arr[], int n);

int card_convr(int x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLNMOPQRSTUVWXYZ";
	int digits = 0;

	if (x == 0)
		d[digits++] = 0;
	else
		while (x) {
			d[digits++] = dchar[x % n];
			x /= n;
		}

	ary_reverse(d, n);

	return digits;
}

void ary_reverse(char arr[], int n) {
	for (int i = 0; i < n / 2; i++)
		swap(char, arr[i], arr[n - i - 1]);
}

int main(void) {
	int num;
	int ch;
	int degree;
	char cnum[512];

	puts("10진수를 기수 변환합니다.");
	do {
		printf("변환하는 음이 아닌 정수 : ");
		scanf_s("%d", &num);
	} while (num <= 0);

	do {
		printf("어떤 진수로 변환할까요?(2-36) : ");
		scanf_s("%d", &ch);
	} while (ch < 2 || ch > 36);

	degree = card_convr(num, ch, cnum);

	printf("%d진수로는 ", ch);
	for (int i = 0; i < degree; i++)
		putchar(cnum[i]);
	printf("입니다.\n");

	return 0;
}