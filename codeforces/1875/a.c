#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve() {
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);

	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += b - 1;
		b = MIN(1 + arr[i], a);
	}
	ans += b;

	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
