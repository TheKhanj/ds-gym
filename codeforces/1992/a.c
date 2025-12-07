#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
	int n = 3;
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	for (int i = 0; i < 5; i++) {
		qsort(arr, n, sizeof(arr[0]), cmp);
		arr[0]++;
	}

	int ans = 1;
	for (int i = 0; i < n; i++)
		ans *= arr[i];
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
