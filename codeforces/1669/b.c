#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
	int n;
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	qsort(arr, n, sizeof(arr[0]), cmp);

	// for (int i = 0; i < n; i++)
	// 	printf("%d ", arr[i]);
	// printf("\n");

	int ans = -1;
	for (int i = 0; i < n;) {
		int base = i;
		while (i < n && arr[base] == arr[i])
			i++;
		if (i - base >= 3) {
			ans = arr[base];
			break;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
