#include <stdio.h>
#include <stdlib.h>

#define check(i, j) (b[(i)] + c[(j)] <= k)

int iless(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int b[n], c[m];
	for (int i = 0; i < n; i++)
		scanf("%d", b + i);
	for (int i = 0; i < m; i++)
		scanf("%d", c + i);
	qsort(b, n, sizeof(b[0]), iless);
	qsort(c, m, sizeof(c[0]), iless);

	int i = 0, j = m - 1;

	long long ans = 0;
	while (i < n) {
		while (j >= 0 && !check(i, j))
			j--;
		if (j < 0)
			break;

		ans += j + 1;

		i++;
	}

	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
