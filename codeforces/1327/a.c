#include <stdio.h>

void solve() {
	long long n, k;
	scanf("%lld %lld", &n, &k);
	int possible = 1;
	if (n < k * k)
		possible = 0;
	if ((n - k * k) % 2 == 1)
		possible = 0;
	printf("%s\n", possible ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
