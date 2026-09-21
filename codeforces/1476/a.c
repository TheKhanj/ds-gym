#include <stdio.h>

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	int sum = (n / k + (n % k == 0 ? 0 : 1)) * k;
	printf("%d\n", sum / n + (sum % n == 0 ? 0 : 1));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
