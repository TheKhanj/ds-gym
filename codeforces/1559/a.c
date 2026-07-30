
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		uint32_t x = UINT32_MAX;
		for (int i = 0; i < n; i++) {
			uint32_t a;
			scanf("%" SCNu32, &a);
			x &= a;
		}
		printf("%" PRIu32 "\n", x);
	}
}
