#include <stdio.h>

typedef struct {
	int y;
	int m;
	int d;
} Date;

int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

Date After(Date x, int n);
Date Before(Date x, int n);

int isleap(int y) {
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int dayofdate(Date date) {
	int days = date.d;

	for (int i = 1; i < date.m; i++)
		days += mdays[isleap(date.y)][i - 1];

	for (int i = 1; i < date.y; i++) {
		for (int j = 1; j <= 12; j++)
			days += mdays[isleap(i)][j - 1];
	}

	return days;
}

Date DateOf(int y, int m, int d) {
	Date date;
	date.y = y;
	date.m = m;
	date.d = d;

	return date;
}

Date After(Date x, int n) {
	if (n < 0)
		return Before(x, -n);

	x.d += n;

	while (x.d > mdays[isleap(x.y)][x.m - 1]) {
		x.d -= mdays[isleap(x.y)][x.m - 1];
		if (++x.m > 12) {
			x.y++;
			x.m = 1;
		}
	}

	return x;
}

Date Before(Date x, int n) {
	if (n < 0)
		return After(x, -n);

	x.d -= n;

	while (x.d < 1) {
		if (--x.m < 1) {
			x.y--;
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}

	return x;
}

void print_date(Date date) {
	char *week[] = { "일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일" };
	int y = date.y;
	int m = date.m;
	int d = date.d;

	printf("%04d년 %02d월 %02d일 %s\n", y, m, d, week[dayofdate(date) % 7]);
}

int main(void) {
	int year, month, day;
	int retry;
	int n;
	Date date;
	
	do {
		printf("년 : ");	scanf_s("%d", &year);
		printf("월 : ");	scanf_s("%d", &month);
		printf("일 : ");	scanf_s("%d", &day);

		date = DateOf(year, month, day);

		printf("몇일 앞 / 뒤의 날짜를 구합니다. : ");
		scanf_s("%d", &n);

		printf("%d일 앞 날짜 : ", n); print_date(After(date, n));
		printf("%d일 뒤 날짜 : ", n); print_date(Before(date, n));
		
		printf("다시 할까요?(1 = 예/0 = 아니오) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}