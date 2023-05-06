#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_lucky(uint32_t x) { return x == 4 || x == 7; }

uint32_t get_lucky_count(uint64_t n) {
	uint32_t ret = 0;
	while (n) {
		if (is_lucky(n % 10)) {
			ret++;
		}

		n /= 10;
	}
	return ret;
}

int32_t main() {
	uint64_t n;
	scanf("%" SCNu64, &n);

	printf("%s", is_lucky(get_lucky_count(n)) ? "YES" : "NO");
}
