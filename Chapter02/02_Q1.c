#include <stdio.h>
#include <stdlib.h>

int minof(const int a[], int n) {
	int min = a[0];

	for (int i = 1; i < n; i++)
		if (min > a[i]) min = a[i];
	
	return min;
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

	printf("최솟값은 %d입니다.\n", minof(height, people));
	free(height);

	return 0;
}