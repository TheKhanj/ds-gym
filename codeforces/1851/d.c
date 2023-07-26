#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int64_t *)a - *(int64_t *)b > 0;
}

int get_missings(int64_t *arr, int n, int64_t missing[2], int64_t *overflow) {
	bool is_there[n + 1];
	for (int i = 0; i < n + 1; i++) {
		is_there[i] = false;
	}

	for (int i = 0; i < n; i++) {
		int64_t x = arr[i] - 1;
		if (x >= 0 && x <= n) {
			if (is_there[x] == true) {
				*overflow = x + 1;
			}
			is_there[x] = true;
			// printf("%ld, ", x);
		} else {
			*overflow = x + 1;
		}
	}
	// printf("\n");

	int missed_count = 0;
	for (int i = 0; i <= n; i++) {
		if (is_there[i] == false) {
			// printf("debug: %d\n", i + 1);
			if (missed_count >= 2) {
				return missed_count + 1;
			}
			missing[missed_count++] = i + 1;
		}
	}

	return missed_count;
}

void solve_test() {
	int n;
	scanf("%d", &n);
	n--;

	int64_t arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr + i);
	}

	for (int i = n - 1; i > 0; i--) {
		arr[i] -= arr[i - 1];
	}

	qsort(arr, n, sizeof(arr[0]), cmp);

	int64_t missed[2];

	int64_t overflow;
	int missed_count = get_missings(arr, n, missed, &overflow);

	bool is_ok = (missed_count == 2 && (missed[0] + missed[1] == overflow)) ||
							 (missed_count == 1);

	printf("%s\n", is_ok ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve_test();
	}
}
