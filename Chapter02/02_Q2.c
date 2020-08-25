#include <stdio.h>
#include <stdlib.h>

int sumof(const int a[], int n) {
	int sum = a[0];

	for (int i = 1; i < n; i++)
		sum += a[i];

	return sum;
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

	printf("키의 합계는 %d입니다.\n", sumof(height, people));
	free(height);

	return 0;
}