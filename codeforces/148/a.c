#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main() {
	int32_t a[4];
	for (int i = 0; i < 4; i++) {
		scanf("%d", a + i);
	}

	int32_t n;
	scanf("%d", &n);

	bool vis[n + 1];
	memset(vis, false, n + 1);

	for (int32_t i = 0; i < 4; i++) {
		for (int32_t j = 0; j <= n; j += a[i]) {
			vis[j] = true;
		}
	}

	int32_t ans = 0;
	for (int32_t i = 1; i <= n; i++) {
		ans += (vis[i] == true ? 1 : 0);
	}

	printf("%d", ans);
}
