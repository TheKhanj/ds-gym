#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define check(a, b, i, j) (a[i] < b[j] && b[j] < a[i + 1])

int iless(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool is_possible() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < m; i++)
		scanf("%d", b + i);
	qsort(a, n, sizeof(a[0]), iless);
	qsort(b, m, sizeof(b[0]), iless);

	if (b[0] < a[0])
		return false;
	if (b[m - 1] > a[n - 1])
		return false;

	int arr[n - 1];
	for (int i = 0, j = 0; i < n - 1; i++) {
		if (j >= m || !check(a, b, i, j)) {
			arr[i] = 0;
			continue;
		}
		int cnt = 0;
		while (j < m && check(a, b, i, j))
			j++, cnt++;

		arr[i] = cnt;
	}
	// printf("debug\n");
	// for (int i = 0; i < n - 1; i++)
	// 	printf("%d ", arr[i]);
	// printf("\n");

	int sum[2][n - 1];

	for (int i = n - 2; i >= 0; i--) {
		sum[1][i] = (i == n - 2 ? 0 : sum[1][i + 1]) + arr[i];
		if (sum[1][i] > n - 2 - i + 1)
			return false;
	}
	for (int i = 0; i < n - 1; i++) {
		sum[0][i] = (i == 0 ? 0 : sum[0][i - 1]) + arr[i];
		// printf("%d ", sum[0][i]);
		if (sum[0][i] > i + 1)
			return false;
	}
	// printf("\n");
	// for (int i = 0; i < n - 1; i++)
	// 	printf("%d ", sum[1][i]);
	// printf("\n");

	if (sum[0][n - 2] + sum[1][0] > n)
		return false;

	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int ok = is_possible();
		printf("%s\n", ok ? "YES" : "NO");
	}
}
