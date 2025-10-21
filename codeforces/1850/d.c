#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(arr[0]), cmp);
	int groups[n], groups_size = 0;
	for (int i = 0; i < n;) {
		int base = i;
		while (i + 1 < n && arr[i + 1] - arr[i] <= k)
			i++;
		groups[groups_size++] = ++i - base;
	}
	qsort(groups, groups_size, sizeof(groups[0]), cmp);
	int max = groups[groups_size - 1];

	printf("%d\n", n - max);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
