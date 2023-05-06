#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t ans = n / 5;
	if (n % 5 != 0) {
		ans++;
	}

	printf("%d", ans);
}
