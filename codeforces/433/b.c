#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	long long sum[2][n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sum[0][i] = arr[i] + (i == 0 ? 0 : sum[0][i - 1]);
	}
	qsort(arr, n, sizeof(arr[0]), cmp);
	for (int i = 0; i < n; i++)
		sum[1][i] = arr[i] + (i == 0 ? 0 : sum[1][i - 1]);

	int m;
	scanf("%d", &m);
	while (m--) {
		int type, l, r;
		scanf("%d %d %d", &type, &l, &r);
		r--, l--, type--;
		printf("%lld\n", sum[type][r] - (l == 0 ? 0 : sum[type][l - 1]));
	}
}
