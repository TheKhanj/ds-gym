#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int arr[4];
	for (int i = 0; i < 4; ++i) {
		scanf("%d", arr + i);
	}

	qsort(arr, 4, sizeof(arr[0]), cmp);

	int max = arr[3];
	for (int i = 0; i < 3; i++) {
		printf("%d ", max - arr[i]);
	}
	printf("\n");
}
