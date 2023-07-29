#include <stdio.h>
#include <stdlib.h>

#define INF ((int)((unsigned int)(1 << 31) - 1))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int arr[m];
	for (int i = 0; i < m; ++i) {
		scanf("%d", arr + i);
	}

	qsort(arr, m, sizeof(arr[0]), cmp);
	int ans = INF;
	for (int i = 0; i < m - n + 1; ++i) {
		ans = MIN(ans, arr[i + n - 1] - arr[i]);
	}

	printf("%d", ans);
}
