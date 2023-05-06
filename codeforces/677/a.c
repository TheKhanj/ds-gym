#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n, h;
	scanf("%d %d", &n, &h);

	int32_t ans = 0;
	for (int i = 0; i < n; i++) {
		int32_t h1;
		scanf("%d", &h1);

		ans += h1 <= h ? 1 : 2;
	}

	printf("%d", ans);
}
