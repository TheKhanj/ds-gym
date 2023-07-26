#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve_test() {
	int n;
	scanf("%d", &n);

	int arr[n], sorted[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sorted[i] = arr[i];
	}

	qsort(sorted, n, sizeof(*sorted), cmp);

	bool is_ok = true;
	for (int i = 0; i < n; i++) {
		// printf("%d ", sorted[i]);
		if (sorted[i] % 2 != arr[i] % 2) {
			is_ok = false;
		}
	}
	// printf("\n");

	printf("%s\n", is_ok ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve_test();
	}
}
