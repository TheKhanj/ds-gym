#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t ans = 0;
	while (n--) {
		int32_t p, q;
		scanf("%d %d", &p, &q);
		ans += p < q - 1 ? 1 : 0;
	}

	printf("%d", ans);
}
