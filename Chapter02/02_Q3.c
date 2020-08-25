#include <stdio.h>
#include <stdlib.h>

double aveof(const int a[], int n) {
	int sum = a[0];

	for (int i = 1; i < n; i++)
		sum += a[i];

	return (double)sum / (double)n;
}

int main(void) {
	int people;
	int *height;

	printf("사람 수 : ");
	scanf_s("%d", &people);

	height = calloc(people, sizeof(int));

	for (int i = 0; i < people; i++) {
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}

	printf("키의 평균은 %.2f입니다.\n", aveof(height, people));
	free(height);

	return 0;
}