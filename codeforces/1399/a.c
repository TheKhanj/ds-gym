#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_possible(int *arr, int size) {
	for (int i = 1; i < size; ++i) {
		if (arr[i] - arr[i - 1] > 1) {
			return false;
		}
	}

	return true;
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
	int n;
	scanf("%d", &n);

	int arr[n];

	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	qsort(arr, n, sizeof(arr[0]), cmp);
	printf("%s\n", is_possible(arr, n) ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
