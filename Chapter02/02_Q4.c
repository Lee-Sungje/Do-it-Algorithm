#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof(const int a[], int n) {
	int max = a[0];

	for (int i = 1; i < n; i++)
		if (max < a[i]) max = a[i];

	return max;
}

int main(void) {
	int people;
	int *height;

	srand(time(NULL));

	people = 5 + rand() % 16;
	height = calloc(people, sizeof(int));

	for (int i = 0; i < people; i++) {
		height[i] = 100 + rand() % 90;
		printf("height[%2d] : %d\n", i, height[i]);
	}

	printf("최댓값은 %d입니다.\n", maxof(height, people));

	free(height);

	return 0;
}