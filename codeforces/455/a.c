#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

struct computed_t {
	int64_t value;
	int64_t count;
};

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void computed_debug(struct computed_t *c) {
	printf("count: %lld, value: %lld\n", c->count, c->value);
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	qsort(arr, n, sizeof(arr[0]), cmp);

	struct computed_t comp[n];

	int size = 0;
	for (int i = 0; i < n;) {
		int curr = arr[i];
		int count = 0;
		while (i < n && arr[i] == curr) {
			i++;
			count++;
		}
		comp[size].value = curr;
		comp[size].count = count;

		size++;
	}

	int64_t dp[size][2];

	for (int i = 0; i < size; i++) {
		// computed_debug(comp + i);
		int64_t cross = comp[i].count * comp[i].value;
		if (i == 0) {
			dp[i][0] = 0;
			dp[i][1] = cross;
		} else {
			dp[i][0] = MAX(dp[i - 1][0], dp[i - 1][1]);

			if (comp[i - 1].value == comp[i].value - 1) {
				dp[i][1] = dp[i - 1][0] + cross;
			} else {
				dp[i][1] = dp[i][0] + cross;
			}
		}
	}

	printf("%lld\n", MAX(dp[size - 1][0], dp[size - 1][1]));
}
