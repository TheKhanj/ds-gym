#include <stdio.h>

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	int gold = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a >= k)
			gold += a;
		if (a == 0 && gold > 0)
			ans++, gold--;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
