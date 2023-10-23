#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve_test() {
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[2][n];
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < n; i++) {
			scanf("%d", arr[j] + i);
		}

	qsort(arr[0], n, sizeof(arr[0][0]), cmp);
	qsort(arr[1], n, sizeof(arr[0][0]), cmp);

	for (int i = 0; i < k; i++) {
		arr[0][i] = MAX(arr[0][i], arr[1][n - 1 - i]);
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[0][i];

	printf("%d\n", sum);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve_test();
	}
}
