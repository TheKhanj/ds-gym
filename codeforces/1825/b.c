#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

int32_t cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void debug(int32_t *arr, size_t size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void solve_test_case() {
	int64_t n, m;
	scanf("%lld %lld", &n, &m);

	int64_t values[n * m];

	for (int64_t i = 0; i < n * m; i++) {
		scanf("%lld", values + i);
	}

	qsort(values, n * m, sizeof(int64_t), cmp);

	int64_t min[2], max[2];
	min[0] = values[0];
	min[1] = values[1];
	max[0] = values[n * m - 1];
	max[1] = values[n * m - 2];

	int64_t bigger_area = MAX(n * (m - 1), (n - 1) * m);
	int64_t smaller_area = MIN(n - 1, m - 1);

	int64_t ans1 =
		bigger_area * max[0] + smaller_area * max[1] + min[0] - min[0] * n * m;
	int64_t ans2 =
		-bigger_area * min[0] - smaller_area * min[1] - max[0] + max[0] * n * m;

	printf("%lld\n", MAX(ans1, ans2));
}

int32_t main() {
	int32_t t;
	scanf("%d", &t);
	while (t--) {
		solve_test_case();
	}
}
