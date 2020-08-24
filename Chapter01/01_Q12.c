#include <stdio.h>

int main(void) {
	int i, j;

	printf("  |");
	for (j = 1; j < 10; j++)
		printf("%3d", j);
	printf("\n--+---------------------------\n");

	for (i = 1; i < 10; i++) {
		printf("%d |", i);
		for (j = 1; j < 10; j++)
			printf("%3d", i * j);

		printf("\n");
	}

	return 0;
}