#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t a, b;
	scanf("%d %d", &a, &b);

	int32_t ans = 0;
	while (a <= b) {
		a *= 3;
		b *= 2;
		ans++;
	}

	printf("%d", ans);
}
