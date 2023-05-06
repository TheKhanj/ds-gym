#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t ans[100];
	for (int32_t i = 0; i < n; i++) {
		int32_t x;
		scanf("%d", &x);

		ans[--x] = i;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i] + 1);
	}
}
