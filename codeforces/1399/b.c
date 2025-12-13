#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void solve() {
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	int min_a = 1e9, min_b = 1e9;
	for (int i = 0; i < n; i++)
		scanf("%d", a + i), min_a = MIN(min_a, a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", b + i), min_b = MIN(min_b, b[i]);

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		int diff_a = a[i] - min_a;
		int diff_b = b[i] - min_b;
		int mn = MIN(diff_a, diff_b);
		ans += mn;
		ans += MAX(diff_a, diff_b) - mn;
	}

	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
