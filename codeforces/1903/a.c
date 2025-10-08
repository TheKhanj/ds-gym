#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool is_sorted(int *arr, int n) {
	int clone[n];
	for (int i = 0; i < n; i++)
		clone[i] = arr[i];
	qsort(clone, n, sizeof(clone[0]), cmp);

	for (int i = 0; i < n; i++)
		if (arr[i] != clone[i])
			return false;

	return true;
}

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%s\n", (is_sorted(arr, n) || k >= 2) ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();

	return 0;
}
