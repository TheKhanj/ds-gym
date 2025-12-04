#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int ans = 1e9 + 10;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		int diff = arr[i] - arr[i - 1];
		if (i != 0) {
			if (diff < 0)
				ans = 0;
			else
				ans = MIN(ans, diff / 2 + 1);
		}
	}
	printf("%d\n", ans < 0 ? 0 : ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
