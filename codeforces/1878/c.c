#include <stdio.h>

void solve() {
	long long n, k, x;
	scanf("%lld %lld %lld", &n, &k, &x);
	long long lsum = (k + 1) * k / 2;
	long long rsum = (n + n - k + 1) * k / 2;
	int ans = lsum <= x && x <= rsum;
	printf("%s\n", ans ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
