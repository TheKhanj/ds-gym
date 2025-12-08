#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int sum[2] = {0, 0};

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		sum[x % 2] += x;
	}

	printf("%s\n", sum[0] > sum[1] ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
