#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int cnt[n];
	for (int i = 0; i < n; i++)
		cnt[i] = 0;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		cnt[--a]++;
		if (cnt[a] >= 3)
			ans = a + 1;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
