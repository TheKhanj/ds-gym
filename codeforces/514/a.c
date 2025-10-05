#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main() {
	uint64_t n;
	scanf("%" SCNu64 "", &n);
	uint64_t ans = 0;
	uint64_t p = 1;
	while (n) {
		int r = n % 10;
		ans += p * ((r >= 5 && !(r == 9 && n / 10 == 0)) ? 9 - r : r);
		n /= 10;
		p *= 10;
	}

	printf("%" PRIu64 "\n", ans);
}
