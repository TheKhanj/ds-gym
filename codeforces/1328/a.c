#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t t;
	scanf("%d", &t);
	while (t--) {
		int32_t a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", (b - a % b) % b);
	}
}
