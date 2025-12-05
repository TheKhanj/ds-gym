#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve() {
	long long n, k;
	scanf("%lld %lld", &n, &k);
	long long x = 1, ans = 0;
	while (x < n) {
		if (x < k) {
			ans++;
			x += x;
			continue;
		}
		ans += (n - x) / k + ((n - x) % k != 0);
		break;
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
