#include <stdint.h>
#include <stdio.h>

#define MAX(x, y) x > y ? x : y

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t ans = 0, current = 0;
	for (int32_t i = 0; i < n; i++) {
		int32_t a, b;

		scanf("%d %d", &a, &b);
		current += b - a;
		ans = MAX(ans, current);
	}

	printf("%d", ans);
}
