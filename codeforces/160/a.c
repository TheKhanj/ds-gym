#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int32_t *)b - *(int32_t *)a; }

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t a[n];
	int32_t sum = 0;

	for (int32_t i = 0; i < n; i++) {
		scanf("%d", a + i);
		sum += a[i];
	}

	qsort(a, n, sizeof(int32_t), cmp);

	int32_t gained_sum = 0, count = 0;
	for (int i = 0; i < n; i++) {
		if (gained_sum > sum - gained_sum) {
			break;
		}

		gained_sum += a[i];
		count++;
	}

	printf("%d", count);
}
