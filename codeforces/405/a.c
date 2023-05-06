#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t arr[n];

	for (int32_t i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	qsort(arr, n, sizeof(int32_t), cmp);

	for (int32_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
