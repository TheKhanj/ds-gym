#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n, l;
	scanf("%d %d", &n, &l);

	int arr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	qsort(arr, n, sizeof(arr[0]), cmp);

	int max_length = arr[0] * 2;
	for (int i = 0; i < n; ++i) {
		int length = (i < n - 1 ? arr[i + 1] - arr[i] : (l - arr[i]) * 2);
		max_length = MAX(max_length, length);
	}

	printf("%.9f\n", (double)max_length / 2.0);
}
