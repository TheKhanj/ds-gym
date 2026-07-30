#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

void solve() {
	long long n;
	scanf("%lld", &n);
	int ans = 1;
	while (n % ans == 0)
		ans++;

	printf("%d\n", ans - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
