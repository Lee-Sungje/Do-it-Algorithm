﻿#include <stdio.h>

#define VMAX 21

typedef struct {
	char	name[20];
	int		height;
	double vision;
} PhysCheck;

double ave_height(const PhysCheck dat[], int n) {
	double sum = 0;

	for (int i = 0; i < n; i++)
		sum += dat[i].height;

	return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[]) {
	for (int i = 0; i < VMAX; i++)
		dist[i] = 0;

	for (int i = 0; i < n; i++)
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
			dist[(int)(dat[i].vision * 10)]++;
}

int main(void) {
	PhysCheck x[] = {
		{ "박현규", 162, 0.3 },
		{ "함진아", 173, 0.7 },
		{ "최윤미", 175, 2.0 },
		{ "홍연의", 171, 1.5 },
		{ "이수진", 168, 0.4 },
		{ "김영준", 174, 1.2 },
		{ "박용규", 169, 0.8 },
		{ "홍길동", 163, 0.4 },
		{ "이순신", 174, 0.4 },
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];

	puts("■□■ 신체검사표 ■□■");
	puts("이름           키   시력 ");
	for (int i = 0; i < nx; i++)
		printf("%-14.14s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);

	printf("\n평균 키 : %5.1f cm\n", ave_height(x, nx));
	dist_vision(x, nx, vdist);

	printf("\n시력 분포\n");
	for (int i = 0; i < VMAX; i++) {
		printf("%3.1f ~ : ", i / 10.0);
		for (int j = 0; j < vdist[i]; j++)
			putchar('*');
		putchar('\n');
	}

	return 0;
}