#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (x < y ? x : y)

int32_t cmp(const void *a, const void *b) {
	return *(int32_t *)a - *(int32_t *)b;
}

int32_t main() {
	int32_t t;
	scanf("%d", &t);
	while (t--) {
		int32_t n, k;
		scanf("%d %d", &n, &k);
		int64_t a[n];
		int64_t total = 0;
		for (int32_t i = 0; i < n; i++) {
			scanf("%" SCNd64, a + i);
			total += a[i];
		}

		qsort(a, n, sizeof(int64_t), cmp);

		int64_t sum = 0, min_sum;
		for (int32_t i = 0; i < 2 * k; i++) {
			sum += a[i];
		}

		min_sum = sum;

		int32_t l = 2 * k - 1, r = n - 1;
		while (k--) {
			sum = sum - a[l] - a[l - 1] + a[r];
			min_sum = MIN(min_sum, sum);
			r--;
			l -= 2;
		}

		printf("%" PRId64 "\n", total - min_sum);
	}
}
