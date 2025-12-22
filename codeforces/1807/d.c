#include <stdio.h>

void solve() {
	int n, q;
	scanf("%d %d", &n, &q);
	int arr[n];
	long long sum[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sum[i] = (i == 0 ? 0 : sum[i - 1]) + arr[i];
	}
	while (q--) {
		long long l, r, k;
		scanf("%lld %lld %lld", &l, &r, &k);
		--l, --r;
		long long s =
				(l == 0 ? 0 : sum[l - 1]) + (sum[n - 1] - sum[r]) + k * (r - l + 1);
		printf("%s\n", s % 2 ? "YES" : "NO");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
