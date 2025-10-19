#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

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
		int diff = arr[n - 1] - arr[0];
		for (int i = 1; i < n; i++)
			diff = MIN(diff, arr[i] - arr[i - 1]);
		printf("%d\n", diff);
	}
}
