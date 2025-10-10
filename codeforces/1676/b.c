#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d", arr + i);
		qsort(arr, n, sizeof(arr[0]), cmp);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += arr[i] - arr[0];
		printf("%d\n", ans);
	}
}
