#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int iless(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool is_possible(int n, int m, int *a, int *b) {
	if (n < 2 * m)
		return false;
	for (int i = 0; i < m; i++)
		if (!(a[i] < b[i]))
			return false;
	for (int j = m - 1, i = n - 1; j >= 0; j--, i--)
		if (!(b[j] < a[i]))
			return false;

	return true;
}

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < m; i++)
		scanf("%d", b + i);

	qsort(a, n, sizeof(a[0]), iless);
	qsort(b, m, sizeof(b[0]), iless);

	printf("%s\n", is_possible(n, m, a, b) ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
