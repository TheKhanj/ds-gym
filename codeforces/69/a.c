#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t x = 0, y = 0, z = 0;
	while (n--) {
		int32_t a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		x += a;
		y += b;
		z += c;
	}

	printf("%s", (x == 0 && y == 0 && z == 0) ? "YES" : "NO");
}
