#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t count[4];
	memset(count, 0, 4 * sizeof(int32_t));

	while (n--) {
		int32_t x;
		scanf("%d", &x);
		count[--x]++;
	}

	int32_t ans = 0;

	// 4
	ans += count[3];

	// 3
	ans += count[2];
	count[0] = (count[0] > count[2] ? count[0] - count[2] : 0);

	// 2
	ans += count[1] / 2 + count[1] % 2;
	if (count[1] % 2 == 1) {
		count[0] = count[0] > 2 ? count[0] - 2 : 0;
	}

	// 1
	ans += count[0] / 4 + (count[0] % 4 == 0 ? 0 : 1);

	printf("%d", ans);
}
